import numpy as np
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


class Perceptron():
    """直線の順伝播と逆伝播を計算するクラス

    self.weight: numpy.ndaaray
        ネットワークの重み
    self.bias: numpy.ndarray
        ネットワークのバイアス
    self.learning_rate: Union[float, numpy.float32]

    self.x: numpy.ndarray
        ネットワークの入力
    self.y: numpy.ndarray
        ネットワークの出力
    """
    def __init__(self, input_size, output_size, learning_rate=0.01):
        """コンストラクタ

        Parameters
        ----------
        input_size: int
            層の入力の次元数（ユニットサイズ）
        output_size: int
            層の出力の次元数（ユニットサイズ）
        learning_rate: float
            学習率
        """

        # 乱数生成器のインスタンスを生成
        rng = np.random.default_rng()
        # 重み(係数)をガウス分布に従う乱数で初期化
        self.w = rng.standard_normal((input_size, output_size))
        # バイアス(切片)をガウス分布に従う乱数で初期化
        self.b = rng.standard_normal(output_size)

        # 学習率を設定
        self.learning_rate = learning_rate

    def forward(self, x):
        """順伝播の関数
        Parameters
        ----------
        x: numpy.ndarray
            入力データ

        Returns
        -------
        self.y: numpy.ndarray
            出力データ
        """

        # 入力を保存しておく
        self.x = x

        # 順伝播y = wx + bを計算
        # self.y = # [TASK] 順伝播を計算
        self.y = x @ self.w + self.b

        return self.y

    def backward(self, grad):
        """逆伝播の関数
        Parameters
        ----------
        grad: numpy.ndarray
            逆伝播で入力された勾配情報

        Returns
        -------
        grad: numpy.ndarray
            逆伝播で入力側に与える勾配情報                
        """

        # 重みとバイアスの勾配を計算
        # g_w = # [TASK] 重みの勾配を計算
        g_w = self.x.T @ grad
        # g_b = # [TASK] バイアスの勾配を計算
        g_b = np.sum(grad, axis=0)

        # 逆伝播する勾配を計算
        g = grad @ self.w.T

        # 重みとバイアスの更新
        # self.w = # [TASK] 重みを更新
        self.w = self.w - self.learning_rate * g_w
        # self.b = # [TASK] バイアスを更新
        self.b = self.b - self.learning_rate * g_b

        return g


class MeanSquaredError():
    """平均二乗誤差関数の順伝播と逆伝播を計算するクラス
    self.diff: Union[numpy.ndarray, numpy.float32]
        入力の差分
    """
    def __init__(self):
        self.diff = None

    def forward(self, y, t):
        """順伝播
        Parameters
        ----------
        y: Union[numpy.ndarray, numpy.float32]
            ネットワークの推論値
        t: Union[numpy.ndarray, numpy.float32]
            教師データ

        Returns
        ----------
        loss: Union[numpy.ndarray, numpy.float32]
            計算した誤差の値
        """

        # 出力と教師データの差分を計算
        self.diff = y - t
        # 平均二乗誤差を計算
        loss = np.mean(self.diff ** 2)
        return loss

    def backward(self):
        """逆順伝播
        Returns
        ----------
        grad: Union[numpy.ndarray, numpy.float32]
            逆伝播で入力側に与える勾配情報
        """

        # 勾配を計算
        g = 2 * self.diff
        return g


def main():

    # CSVファイルの読み込み
    data_path = "../data/advertising.csv"
    header, data = load_csv(data_path)

    # 説明変数と目的変数に分割
    #     目的変数をtとしている
    x = data[:, :-1]
    t = data[:, -1].reshape(-1, 1)

    x = x / x.max(axis=0)
    t = t / t.max(axis=0)


    # 学習率
    learning_rate = 0.0000001

    # 単純パーセプトロンのインスタンスを生成
    perceptron = Perceptron(x.shape[1], 1, learning_rate=learning_rate)

    # 誤差関数のインスタンスを生成
    loss_function = MeanSquaredError()

    # 繰り返し学習する回数
    max_iteration = 10000

    # 誤差の履歴を保存するリストを初期化
    loss_list = []
    
    # 学習ループ
    for i in range(max_iteration):
        # 順伝播
        y = perceptron.forward(x)

        # 誤差計算
        loss = loss_function.forward(y, t)

        # 誤差関数の勾配を計算
        g = loss_function.backward()
        # 誤差逆伝播で勾配を計算し更新
        g = perceptron.backward(g)

        # 誤差を履歴としてリストに結合
        loss_list.append(loss)

        # ログを出力
        _log = 'Iteration: {:4d},  Loss: {:7.4f}'
        print(_log.format(i + 1, loss))

    print("重み")
    print(perceptron.w)
    print("バイアス")
    print(perceptron.b)

    # グラフに描画(横軸が実測値，縦軸が予測値の散布図)
    # 直線上に点が分布していれば予測精度が高いことを示す
    plt.figure(figsize=(6,6))
    plt.scatter(t, y, alpha=0.7)
    plt.xlabel("Actual Sales")
    plt.ylabel("Predicted Sales")
    plt.plot([y.min(), y.max()], [y.min(), y.max()], 'r--')
    plt.tight_layout()
    plt.savefig('../outputs/advertising_actual_vs_predicted_3.png')

    # 誤差の履歴をプロット
    plt.figure()
    plt.plot(range(1, max_iteration + 1), loss_list)
    plt.xlabel("Iteration")
    plt.ylabel("Mean Squared Error Loss")
    plt.tight_layout()
    plt.savefig('../outputs/advertising_loss_history_3.png')
    

if __name__ == "__main__":
    main()
