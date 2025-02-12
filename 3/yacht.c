#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_COUNT 5
#define CATEGORY_COUNT 12
#define MAX_PLAYERS 4

// サイコロの状態を管理する構造体
typedef struct {
    int dice[DICE_COUNT];   // サイコロの目
    int hold[DICE_COUNT];   // 保持フラグ
} DiceState;

// プレイヤーの状態を管理する構造体
typedef struct {
    int scores[CATEGORY_COUNT]; // 各カテゴリのスコア
    int totalScore;             // 合計スコア
    int usedCategories[CATEGORY_COUNT]; // 使用済みカテゴリ
} Player;

// サイコロを振る関数
void rollDice(DiceState *diceState) {
    for (int i = 0; i < DICE_COUNT; i++) {
        if (!diceState->hold[i]) {
            diceState->dice[i] = rand() % 6 + 1; // 1から6の範囲でランダムに生成
        }
    }
}

// サイコロの状態を表示
void printDice(const DiceState *diceState) {
    for (int i = 0; i < DICE_COUNT; i++) {
        printf("サイコロ %d: %d\n", i + 1, diceState->dice[i]);
    }
}

// ユーザーに保持するサイコロを入力させる
void getHoldInput(DiceState *diceState) {
    int holdIndex;
    for (int i = 0; i < DICE_COUNT; i++) {
        diceState->hold[i] = 0; // 初期化
    }
    printf("保持したいサイコロの番号を入力してください (1-5)。終了するには0を入力してください: ");
    while (scanf("%d", &holdIndex) && holdIndex != 0) {
        if (holdIndex >= 1 && holdIndex <= 5) {
            diceState->hold[holdIndex - 1] = 1;
        }
    }
}

// スコアを計算する
int calculateScore(const DiceState *diceState, int category) {
    int score = 0;
    int counts[6] = {0};

    for (int i = 0; i < DICE_COUNT; i++) {
        counts[diceState->dice[i] - 1]++;
    }

    switch (category) {
        case 1: score = counts[0] * 1; break;
        case 2: score = counts[1] * 2; break;
        case 3: score = counts[2] * 3; break;
        case 4: score = counts[3] * 4; break;
        case 5: score = counts[4] * 5; break;
        case 6: score = counts[5] * 6; break;
        case 7: // フルハウス
            {
                int threeOfKind = 0, pair = 0;
                for (int i = 0; i < 6; i++) {
                    if (counts[i] == 3) threeOfKind = 1;
                    if (counts[i] == 2) pair = 1;
                }
                if (threeOfKind && pair) score = 25;
            }
            break;
        case 8: // フォーカインド
            for (int i = 0; i < 6; i++) {
                if (counts[i] >= 4) score = 30;
            }
            break;
        case 9: // スモールストレート
            if ((counts[0] && counts[1] && counts[2] && counts[3]) ||
                (counts[1] && counts[2] && counts[3] && counts[4]) ||
                (counts[2] && counts[3] && counts[4] && counts[5])) {
                score = 30;
            }
            break;
        case 10: // ラージストレート
            if ((counts[0] && counts[1] && counts[2] && counts[3] && counts[4]) ||
                (counts[1] && counts[2] && counts[3] && counts[4] && counts[5])) {
                score = 40;
            }
            break;
        case 11: // ヨット
            for (int i = 0; i < 6; i++) {
                if (counts[i] == 5) score = 50;
            }
            break;
        case 12: // チャンス
            for (int i = 0; i < DICE_COUNT; i++) {
                score += diceState->dice[i];
            }
            break;
        default:
            printf("無効なカテゴリです\n");
            break;
    }

    return score;
}

// カテゴリ一覧を表示
void printCategories() {
    printf("カテゴリ:\n");
    printf("1. エース (1の目)\n");
    printf("2. ツー (2の目)\n");
    printf("3. スリー (3の目)\n");
    printf("4. フォー (4の目)\n");
    printf("5. ファイブ (5の目)\n");
    printf("6. シックス (6の目)\n");
    printf("7. フルハウス\n");
    printf("8. フォーカード\n");
    printf("9. スモールストレート\n");
    printf("10. ラージストレート\n");
    printf("11. ヨット\n");
    printf("12. チャンス\n");
}

// プレイヤーのスコアを更新する
void updateScore(Player *player, int category, int score) {
    player->scores[category - 1] = score;
    player->totalScore += score;
    player->usedCategories[category - 1] = 1;
}

// 全プレイヤーのスコアを表示
void printScores(const Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("プレイヤー %d のスコア:\n", i + 1);
        for (int j = 0; j < CATEGORY_COUNT; j++) {
            printf("  カテゴリ %d: %d\n", j + 1, players[i].scores[j]);
        }
        printf("  合計スコア: %d\n", players[i].totalScore);
    }
}

// スコアをファイルに保存
void saveScoresToFile(const Player players[], int playerCount) {
    FILE *file = fopen("scores.txt", "w");
    if (!file) {
        perror("ファイルを開けませんでした");
        return;
    }

    fprintf(file, "最終スコア:\n");
    for (int i = 0; i < playerCount; i++) {
        fprintf(file, "プレイヤー %d:\n", i + 1);
        for (int j = 0; j < CATEGORY_COUNT; j++) {
            fprintf(file, "  カテゴリ %d: %d\n", j + 1, players[i].scores[j]);
        }
        fprintf(file, "  合計スコア: %d\n", players[i].totalScore);
    }

    fclose(file);
    printf("スコアが 'scores.txt' に保存されました。\n");
}

int main() {
    DiceState diceState;
    Player players[MAX_PLAYERS] = {0};
    int playerCount, category, score;
    char choice;
    srand(time(NULL));

    printf("プレイヤーの人数を入力してください (1-4): ");
    scanf("%d", &playerCount);
    if (playerCount < 1 || playerCount > 4) {
        printf("無効なプレイヤー人数です。1から4の間で入力してください。\n");
        return 1;
    }

    for (int turn = 0; turn < CATEGORY_COUNT; turn++) {
        for (int player = 0; player < playerCount; player++) {
            printf("\nプレイヤー %d のターン %d (合計スコア: %d):\n", player + 1, turn + 1, players[player].totalScore);

            // サイコロの保持をリセット
            for (int i = 0; i < DICE_COUNT; i++) {
                diceState.hold[i] = 0;
            }

            rollDice(&diceState);
            printf("初回の振り:\n");
            printDice(&diceState);

            for (int i = 0; i < 2; i++) {
                printf("もう一度振りますか？ (y/n): ");
                scanf(" %c", &choice);
                if (choice == 'y') {
                    getHoldInput(&diceState);
                    rollDice(&diceState);
                    printf("振り %d:\n", i + 2);
                    printDice(&diceState);
                } else {
                    break;
                }
            }

            printf("最終的なサイコロ:\n");
            printDice(&diceState);

            printCategories();
            printf("スコアを記録するカテゴリ番号を入力してください (1-12): ");
            scanf("%d", &category);

            while (players[player].usedCategories[category - 1]) {
                printf("カテゴリ %d は既に使用されています。別のカテゴリを選択してください: ", category);
                scanf("%d", &category);
            }

            score = calculateScore(&diceState, category);
            updateScore(&players[player], category, score);

            printf("プレイヤー %d のカテゴリ %d のスコアは: %d\n", player + 1, category, score);
        }
    }

    printf("\n最終スコア:\n");
    printScores(players, playerCount);
    saveScoresToFile(players, playerCount);

    return 0;
}
