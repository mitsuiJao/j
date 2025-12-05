import os
import numpy as np

import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader
import torchvision
import torchvision.transforms as transforms
import matplotlib.pyplot as plt


def load_csv(path: str):
    """CSVファイルを読み込み，ヘッダーとデータを返す関数

    numpy.genfromtxtとnumpy.loadtxtを用いてCSVを読み込む

    Parameters
    ----------
    path: str
        CSVファイルのパス

    Returns
    -------
    header : list
        ヘッダー名のリスト
    data : numpy.ndarray of float, shape (n_rows, n_cols)
        データの数値配列
    """

    # ヘッダーを取得（1行目）
    header = np.genfromtxt(path, delimiter=',', dtype=str, max_rows=1)
    header = [h.strip() for h in header.tolist()]

    # 2行目以降のデータを取得
    data = np.loadtxt(path, delimiter=',', skiprows=1)

    return header, data


class NeuealNetworkPredicter(nn.Module):
    """
    ニューラルネットワークによる回帰モデル
    """

    def __init__(self):
        super().__init__()
        self.fc1 = nn.Linear(3,1)

    def forward(self, x):
        """
        Forward pass of the classifier

        Parameters
        ----------
        x : torch.Tensor
            入力画像テンソル，形状は (k, n)

        Returns
        -------
        torch.Tensor
            出力ロジット，形状は (k, 1)
        """
        x = self.fc1(x)
        return x


def main():

    # CSVファイルの読み込み
    data_path = "../data/advertising.csv"
    header, data = load_csv(data_path)

    # 説明変数と目的変数に分割
    #     目的変数をtとしている
    x = data[:, :-1]
    t = data[:, -1].reshape(-1, 1)

    # numpy.ndarray から torch.Tensor に変換
    # inputs = # [TASK] xをtorch.Tensorに変換
    inputs = torch.tensor(x, dtype=torch.float32)
    # targets = # [TASK] tをtorch.Tensorに変換
    targets = torch.tensor(t, dtype=torch.float32)

    # 単純パーセプトロンのインスタンスを生成
    model = NeuealNetworkPredicter()

    # 誤差関数の宣言
    criterion = nn.MSELoss()

    # 学習率の設定
    learning_rate = 0.00001

    # 最適化器の宣言
    optimizer = optim.SGD(model.parameters(), lr=learning_rate)

    # 繰り返し学習する回数
    max_epochs = 300

    # 誤差の履歴を保存するリストを初期化
    loss_list = []

    # モデルを学習モードに設定
    model.train()
    # モデルの学習
    for epoch in range(max_epochs):
        # 順伝播
        outputs = model(inputs)
        # 誤差計算
        loss = criterion(outputs, targets)

        # 重みの更新
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
  
        # 誤差の履歴を保存
        loss_list.append(loss.item())

        print(
            f"Epoch [{epoch+1}/{max_epochs}] "
            f"Train Loss: {loss.item():.4f}"
        )

    print("重み")
    print(model.fc1.weight.data)

    # グラフに描画(横軸が実測値，縦軸が予測値の散布図)
    # 直線上に点が分布していれば予測精度が高いことを示す
    plt.figure(figsize=(6,6))
    y = outputs.detach().numpy()
    plt.scatter(t, y, alpha=0.7)
    plt.xlabel("Actual Sales")
    plt.ylabel("Predicted Sales")
    plt.plot([y.min(), y.max()], [y.min(), y.max()], 'r--')
    plt.tight_layout()
    plt.savefig('../outputs/advertising_actual_vs_predicted.png')

    # 誤差の履歴をプロット
    plt.figure()
    plt.plot(range(1, max_epochs + 1), loss_list)
    plt.xlabel("Iteration")
    plt.ylabel("Mean Squared Error Loss")
    plt.tight_layout()
    plt.savefig('../outputs/advertising_loss_history.png')
    

if __name__ == "__main__":
    main()
