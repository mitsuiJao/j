import numpy as np
import matplotlib.pyplot as plt


def least_squares_method(x: np.ndarray, y: np.ndarray):
    """
    最小二乗法で一次式 y = ax + b の係数a, bを求める関数

    Parameters
    ----------
    x: numpy.ndarray
        説明変数（x座標）の配列
    y: numpy.ndarray
        目的変数（y座標）の配列

    Returns
    -------
    a: numpy.float64 
        回帰直線の傾き
    b: numpy.float64 
        回帰直線の切片

    Examples
    --------
    >>> x = np.array([0, 1, 2, 3])
    >>> y = np.array([1, 2, 3, 4])
    >>> a, b = least_squares_method(x, y)
    >>> print(a, b)
    1.0 1.0
    """

    # xの要素数
    n = len(x)

    # xの平均
    mean_x = np.mean(x)
    # yの平均
    mean_y = np.mean(y)

    # xの分散
    var_x = np.sum(np.pow(x, 2) - mean_x**2 ) / n
    # xとyの共分散
    var_xy = np.sum(x*y) / n - mean_x * mean_y

    # 傾きaと切片bの計算
    a = var_xy / var_x
    b = mean_y - a * mean_x

    return a, b


def main():
    # サンプルデータ（x, y）
    x = np.array([0, 1, 2, 3, 4, 5])
    y = np.array([2, 2.8, 3.6, 4.5, 5.1, 5.9])

    # 最小二乗法で直線の係数を求める
    a, b = least_squares_method(x, y)
    # 求めたパラメータの確認
    print(f"演習で求めたパラメータ:       a={a:.6f}, b={b:.6f}")

    # 最小二乗法で求めたパラメータを使ってyの値を計算(予測)
    y_fit = a * x + b

    # NumPyのlstsq関数を使った場合の確認(比較のため)
    A = np.vstack([x, np.ones(len(x))]).T
    a, b = np.linalg.lstsq(A, y, rcond=None)[0]
    print(f"ライブラリで求めたパラメータ: a={a:.6f}, b={b:.6f}")

    # プロット
    plt.scatter(x, y, label="Data")
    plt.plot(x, y_fit, "r-", label=f'Fit: y={a:.2f}x+{b:.2f}')
    plt.xlabel("x")
    plt.ylabel("y")
    plt.xlim([0, 5])
    plt.ylim([0, 8])
    plt.legend()
    plt.savefig("../outputs/least_squares_method.png")


if __name__ == "__main__":
    main()
