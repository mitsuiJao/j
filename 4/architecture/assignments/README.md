## コツ
- コンポーネントは下位から書くのがいいと思う（経験則）
- 型に厳しいのでそこだけ注意、でも使うものはstd_logicとintegerくらい


## 基本構造
```v
library IEEE;                       -- ライブラリ

entity Add is                       -- 入出力
    port (
        IN : in integer range 0 to 3;
        OUT
    );
end Add;                            -- entity名end

architecture STRUCTURE of Add is    -- プログラムの中身, architecture名 of entity名 is
    component Adder                 -- 呼び出すentity名
    port (
        INA :                       -- entityコピペ
    )

    signal data_intd : integer ...  -- ワイヤーみたいにつなぐ, tag名

begin

	AD : Adder port map (           -- コンポーネント配置、インスタンス名 : entity名 port map
		INA	=> INA,                 -- インスタンスポート => インスタンス外ポート（入出力関係ない）
		INB	=> INB,
		SUM	=> data_intd
	);

	P8 : Pattern_8 port map (
		DATA => data_intd,
		SEG7 => SEG7
	)

end STRUCTURE;                      -- architecture名end
```

- エンティティ名とファイル名は一致させるべき, 1対1（Javaのクラス名のように）
- 呼び出し側は基本エンティティ単位（エンティティ名）
- architectureの`process`はその値が変更されたら実行する（感度リスト）

### 命名ケース
- entyty, architecture, composent : UpperCamelCase
- signal, variable : snake_case
- port, generic : UPPER_SNAKE_CASE

## 備考
