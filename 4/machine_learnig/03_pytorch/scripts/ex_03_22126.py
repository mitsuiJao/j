import os

import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader
import torchvision
import torchvision.transforms as transforms
import matplotlib.pyplot as plt


def plot_losses(train_losses, test_losses, output_dir="../outputs"):
    """
    学習とテストの損失履歴を描画し，画像として保存する関数

    Parameters
    ----------
    train_losses : list of float
        学習データの各エポックの平均損失
    test_losses : list of float
        テストデータの各エポックの平均損失
    output_dir : str
        出力先ディレクトリのパス
    """
    os.makedirs(output_dir, exist_ok=True)
    epochs = range(1, len(train_losses) + 1)

    plt.figure()
    plt.plot(epochs, train_losses, label="Train Loss")
    plt.plot(epochs, test_losses, label="Test Loss")
    plt.xlabel("Epoch")
    plt.ylabel("Loss")
    plt.legend()

    out_path = os.path.join(output_dir, "mnist_loss_ex_03_22126_epoch100.png")
    plt.savefig(out_path)
    plt.close()

    print(f"Saved loss figure to {out_path}")


def plot_accuracy(train_accs, test_accs, output_dir="../outputs"):
    """
    学習とテストの正答率履歴を描画し，画像として保存する関数

    Parameters
    ----------
    train_accs : list of float
        学習データの各エポックの正答率（百分率）
    test_accs : list of float
        テストデータの各エポックの正答率（百分率）
    output_dir : str
        出力先ディレクトリのパス
    """
    os.makedirs(output_dir, exist_ok=True)
    epochs = range(1, len(train_accs) + 1)

    plt.figure()
    plt.plot(epochs, train_accs, label="Train Acc")
    plt.plot(epochs, test_accs, label="Test Acc")
    plt.xlabel("Epoch")
    plt.ylabel("Accuracy (%)")
    plt.legend()

    out_path = os.path.join(output_dir, "mnist_accuracy_ex_03_22126_epoch100.png")
    plt.savefig(out_path)
    plt.close()



class NeuealNetworkCls(nn.Module):
    """
    ニューラルネットワークによる分類モデル（MNIST 用の単純 MLP）

    Notes
    -----
    入力は 28x28 のグレースケール画像であり，Flatten 後の次元は 784 (=28*28) になる
    """

    def __init__(self):
        super().__init__()
        self.flatten = nn.Flatten()
        self.fc1 = nn.Linear(784, 100)
        self.relu = nn.ReLU()
        self.fc2 = nn.Linear(100, 10)

    def forward(self, x):
        """
        Forward pass of the classifier

        Parameters
        ----------
        x : torch.Tensor
            入力画像テンソル，形状は (N, 1, 28, 28)

        Returns
        -------
        torch.Tensor
            出力ロジット，形状は (N, 10)
        """
        x = self.flatten(x)
        x = self.fc1(x)
        x = self.relu(x)
        x = self.fc2(x)
        return x


def load_mnist_dataloaders(batch_size=128):
    """
    MNIST のデータセットを読み込み，DataLoader を作成する関数

    Parameters
    ----------
    batch_size : int, optional
        ミニバッチサイズ

    Returns
    -------
    tuple of DataLoader
        (train_loader, test_loader)

    """
    transform = transforms.Compose([transforms.ToTensor()])

    train_dataset = torchvision.datasets.MNIST(
        root="../data", train=True, download=True, transform=transform
    )
    test_dataset = torchvision.datasets.MNIST(
        root="../data", train=False, download=True, transform=transform
    )

    train_loader = DataLoader(train_dataset, batch_size=batch_size,shuffle=True)
    test_loader = DataLoader(test_dataset, batch_size=batch_size, shuffle=False)

    return train_loader, test_loader


def main():
    """
    MNIST の分類モデルを学習し，各エポックにおける損失と正答率を表示し，
    終了後に別々の画像として保存するメイン処理

    Notes
    -----
    学習，評価，可視化までを一括で実行する
    """

    batch_size = 128
    max_epochs = 100

    learning_rate = 0.01


    train_loader, test_loader = load_mnist_dataloaders(
        batch_size=batch_size,
    )

    # モデルのインスタンスを生成
    model = NeuealNetworkCls()
    
    # 誤差関数の宣言
    criterion = nn.CrossEntropyLoss()
    # 最適化器の宣言
    optimizer = optim.SGD(model.parameters(), lr=learning_rate)

    # 各エポックの損失と正答率を保存するリスト
    train_losses = []
    test_losses = []
    train_accs = []
    test_accs = []

    # モデルの学習
    for epoch in range(max_epochs):
        running_loss = 0.0
        correct_train = 0
        total_train = 0

        # モデルを学習モードに設定
        model.train()
        # 学習ループ
        for inputs, labels in train_loader:
            # 順伝播
            outputs = model(inputs)
            # 誤差計算
            loss = criterion(outputs, labels)

            # 重みの更新
            optimizer.zero_grad()
            loss.backward()
            optimizer.step()

            # 誤差を累積
            running_loss += loss.item()
            # 正答数を累積
            _, predicted = outputs.max(1)
            total_train += labels.size(0)
            correct_train += (predicted == labels).sum().item()

        # 学習データの平均誤差と正答率を計算
        avg_train_loss = running_loss / len(train_loader)
        train_acc = 100 * correct_train / total_train

        running_test_loss = 0.0
        correct_test = 0
        total_test = 0

        # モデルを学習モードに設定
        model.eval()
        # テストループ
        with torch.no_grad():
            for inputs, labels in test_loader:
                # 順伝播
                outputs = model(inputs)
                # 誤差計算
                loss = criterion(outputs, labels)

                # 誤差を累積
                running_test_loss += loss.item()
                # 正答数を累積
                _, predicted = outputs.max(1)
                total_test += labels.size(0)
                correct_test += (predicted == labels).sum().item()

        # 学習データの平均誤差と正答率を計算
        avg_test_loss = running_test_loss / len(test_loader)
        test_acc = 100 * correct_test / total_test

        # リストに履歴を結合
        train_losses.append(avg_train_loss)
        test_losses.append(avg_test_loss)
        train_accs.append(train_acc)
        test_accs.append(test_acc)

        print(
            f"Epoch [{epoch+1}/{max_epochs}] "
            f"Train Loss: {avg_train_loss:.4f} Train Acc: {train_acc:.2f}% "
            f"Test Loss: {avg_test_loss:.4f} Test Acc: {test_acc:.2f}%"
        )

    # 図の保存
    plot_losses(train_losses, test_losses, output_dir="../outputs")
    plot_accuracy(train_accs, test_accs, output_dir="../outputs")


if __name__ == "__main__":
    main()
