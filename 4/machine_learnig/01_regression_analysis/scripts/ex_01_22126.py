import numpy as np
import matplotlib.pyplot as plt

patterns = {
    "TV": [0, 1],
    "Radio": [0, 2],
    "Newspaper": [0, 3],
    "all": [0, 1, 2, 3],
    "interaction_term": [0, 1, 2, 3, 4, 5, 6],
    "interaction_term_TV_Radio": [0, 1, 2, 3, 4],
    "interaction_term_TV_Ns" : [0, 1, 2, 3, 5],
    "interaction_term_Radio_Ns" : [0, 1, 2, 3, 6],
}

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


def regression_analysis(x: np.ndarray, y: np.ndarray,) -> np.ndarray:
    """回帰分析によりパラメータ推定する関数
    
    設計行列xと目的変数yに対して，正規行列によりパラメータを推定

    Parameters
    ----------
    x : numpy.ndarray of float, shape (n_samples, n_features_plus1)
        切片用の 1 列を含む設計行列
    y : numpy.ndarray of float, shape (n_samples,)
        目的変数ベクトル

    Returns
    -------
    w : numpy.ndarray of float, shape (n_features_plus1,)
        切片を含む全パラメータベクトル
    """

    w = np.linalg.inv(x.T @ x) @ x.T @ y
    return w


def predict(x: np.ndarray, w: np.ndarray) -> np.ndarray:
    """設計行列とパラメータベクトルから予測値を計算する

    Parameters
    ----------
    x : ndarray of float, shape (n_samples, n_features_plus1)
        切片列を含む設計行列
    w : ndarray of float, shape (n_features_plus1,)
        切片を含むパラメータベクトル

    Returns
    -------
    y_pred : ndarray of float, shape (n_samples,)
        予測値
    """

    y_pred = x @ w
    return y_pred

def calc_r2(y: np.ndarry, y_pred: np.ndarry) -> np.ndarray:
    y_mean = np.mean(y)
    return 1 - (np.sum((y - y_pred) ** 2) / np.sum((y - y_mean) ** 2))

def calc_rmse(y, y_pred):
    return np.sqrt(1 / y.size * np.sum((y - y_pred) ** 2)) # np.ndarray.sizeは要素数だよー

def main():

    # CSVファイルの読み込み
    data_path="../data/advertising.csv"
    header, data = load_csv(data_path)

    # 説明変数と目的変数に分割
    x = data[:, :-1]
    y = data[:, -1]

    # 目的変数の列名を除去(説明変数だけのリストにする)
    header = header[:-1]
    header.append("TV_Radio")
    header.append("TV_Ns")
    header.append("Radio_Ns")

    # バイアス項：要素1の行列，xの行数×1
    #bias = # [TASK] xの行数に合わせたバイアス項の列ベクトルを作成
    bias = np.ones((x.shape[0], 1))

    # 交互作用項 x[:, 0] i行0列 かっこ必須
    tv_radio = (x[:, 0] * x[:, 1]).reshape(-1, 1)
    tv_newspaper = (x[:, 0] * x[:, 2]).reshape(-1, 1)
    radio_newspaper = (x[:, 1] * x[:, 2]).reshape(-1, 1)

    # r2, rmse x pat
    result = np.zeros((2, len(patterns)))

    # 説明変数に切片列を追加して設計行列を作成
    #x = # [TASK] バイアス項の列を説明変数xの先頭に結合して設計行列を作成
    x_ori = np.hstack((bias, x, tv_radio, tv_newspaper, radio_newspaper))
    for i, pat in enumerate(patterns):
        x = x_ori[:, patterns[pat]] # <----- 0は必ず残す

        # 回帰分析
        w = regression_analysis(x, y)

        # 切片と回帰係数に分割
        intercept = w[0]
        coefs = w[1:]

        # 予測値の計算と評価指標の算出
        y_pred = predict(x, w)

        R2 = calc_r2(y, y_pred)
        rmse = calc_rmse(y, y_pred)

        result[0, i] = R2
        result[1, i] = rmse

        # 求めたパラメータの表示
        print(f"{pat} 回帰分析結果")
        print(f"切片: {intercept}") 
        for i in range(len(coefs)):
            print(f"回帰係数({header[i]}): {coefs[i]}")
        print("R^2:", R2)
        print("RMSE:", rmse)
        
        print("-------------------------------------")

        # NumPyを用いて回帰分析（確認用）
        # SVDにより安定した数値をを解を算出しているため，結果が異なる場合がある
        w, residuals, rank, s = np.linalg.lstsq(x, y, rcond=None)
        intercept = w[0]
        coefs = w[1:]
        print("NumPyによる回帰分析結果（確認用）")
        print(f"切片: {intercept}") 
        for i in range(len(coefs)):
            print(f"回帰係数({header[i]}): {coefs[i]}")

        print("\n=====================================\n")            

        # グラフに描画(横軸が実測値，縦軸が予測値の散布図)
        # 直線上に点が分布していれば予測精度が高いことを示す
        plt.figure(figsize=(6,6))
        plt.scatter(y, y_pred, alpha=0.7)
        plt.xlabel("Actual Sales")
        plt.ylabel("Predicted Sales")
        plt.plot([y.min(), y.max()], [y.min(), y.max()], 'r--')
        plt.tight_layout()
        plt.savefig(f'../outputs/{pat}.png')

    # 下6桁, カンマ区切りcsv
    np.savetxt("../outputs/result.csv", result, delimiter=",", fmt="%.6f")

if __name__ == "__main__":
    main()
