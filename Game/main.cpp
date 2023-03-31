#include "DxLib.h"

#include "math.h"
#include "game.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // windowモード設定
    ChangeWindowMode(Game::kWindowMode);

    // ウインドウ名設定
    SetMainWindowText("ゲーム名");

    // 画面サイズの設定
    SetGraphMode(Game::kScreenWindth, Game::kScreenHeight, Game::kColorDepth);

    if (DxLib_Init() == -1)        // ＤＸライブラリ初期化処理
    {
        return -1;            // エラーが起きたら直ちに終了
    }

    int handle = LoadGraph("../Data/Knight.png");

    // ダブルバッファモード
    SetDrawScreen(DX_SCREEN_BACK);

    int animeNum = 0;

    while (ProcessMessage() == 0)
    {
        LONGLONG time = GetNowHiPerformanceCount();

        // 画面のクリア
        ClearDrawScreen();
        animeNum++;
        if (animeNum > 8)
        {
            animeNum = 0;
        }

        DrawRectRotaGraph(200,
            200,			//表示座標
            16 * 0, 16 * animeNum,			//切り取り左上
            16, 16,							//幅、高さ
            3.0f, 0.0f,						//拡大率、回転角度
            handle, true);

        // 裏画面を表画面を入れ替える
        ScreenFlip();

        // escキーを押したら終了する
        if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

        // fpsを60に固定
        while (GetNowHiPerformanceCount() - time < 16667)
        {

        }
    }

    DxLib_End();                // ＤＸライブラリ使用の終了処理

    return 0;                // ソフトの終了
}