import numpy as np
import matplotlib.pyplot as plt


def linear_function(x, w, b):
    """一次関数
    Parameters
    ----------
    x: numpy.ndarray
        関数の入力値が格納された配列
    w: numpy.float32
        一次関数の傾き（重み）
    b: numpy.float32
        一次関数の切片（バイアス）

    Returns
    ----------
    fx: numpy.ndarray
        一次関数の出力値が格納された配列
    """
    fx = w * x + b
    return fx


def gradient_method(x, y, learning_rate, max_iteration):
    """勾配法
    Parameters
    ----------
    x: numpy.ndarray
        関数の入力値が格納された配列
    y: numpy.ndarray
        関数で推定したい値が格納された配列

    Returns
    ----------
    w: numpy.float32
        一次関数の傾き（重み）
    b: numpy.float32
        一次関数の切片（バイアス）
    """

    # 初期パラメータはランダム
    rng = np.random.default_rng()
    w = rng.standard_normal()
    b = rng.standard_normal()

    for i in range(max_iteration):
        # 直線回帰
        fx = linear_function(x, w, b)

        # 重みとバイアスの勾配を計算
        g_w = np.mean(x*(fx-y))
        g_b = np.mean(fx - y)

        # パラメータ更新
        w = w - (learning_rate*g_w)
        b = b - (learning_rate*g_b)

        # 誤差計算
        e = np.mean((fx-y)**2)

        # ログを出力
        _log = 'Iteration: {:3d},  Error: {:10.4f},  w: {:6.4f},  b: {:6.4f}'
        print(_log.format(i + 1, e, w, b))

    return w, b


def main():
    # サンプルデータ（x, y）
    x = np.array([0, 1, 2, 3, 4, 5])
    y = np.array([2, 2.8, 3.6, 4.5, 5.1, 5.9])

    # 勾配降下法により直線のパラメータを求める
    w, b = gradient_method(x, y, 0.1, 100)
    print(w, b)

    # 最小二乗法で求めたパラメータを使ってyの値を計算(予測)
    y_fit = w * x + b

    # プロット
    plt.scatter(x, y, label="Data")
    plt.plot(x, y_fit, "r-", label=f'Fit: y={w:.2f}x+{b:.2f}')
    plt.xlabel("x")
    plt.ylabel("y")
    plt.xlim([0, 5])
    plt.ylim([0, 8])
    plt.legend()
    plt.savefig("../outputs/gradient_method.png")


if __name__ == "__main__":
    main()
