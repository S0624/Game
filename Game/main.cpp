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

    //int witchHandle = LoadGraph("../Data/Witch.png");
    int witchHandle = LoadGraph("../Data/Witch2.png");
    int Handle1 = LoadGraph("../Data/charge1.png");
    int handle = LoadGraph("../Data/Knight.png");

    // ダブルバッファモード
    SetDrawScreen(DX_SCREEN_BACK);

    int animeNum = 0;
    int animeNum1 = 0;
    int animeNum2 = 0;
    int animeFrame = 0;
    int posX = 200;

    while (ProcessMessage() == 0)
    {
        LONGLONG time = GetNowHiPerformanceCount();

        // 画面のクリア
        ClearDrawScreen();
        animeFrame++;
        if (animeFrame > 10)
        {
            animeNum++;
            animeNum1++;
            animeNum2++;
            posX += 30;
            animeFrame = 0;
        }
        if (animeNum2 >= 7)
        {
            animeNum2 = 0;
        }
        if (animeNum >= 9)
        {
            animeNum = 0;
        }
        if (animeNum1 >= 5)
        {
            animeNum1 = 0;
        }
        if (posX > Game::kScreenWindth)
        {
            posX = 0;
            animeNum = 0;
        }

        DrawRectRotaGraph(posX,
            600,			//表示座標
            16 * 0, 16 * animeNum2,			//切り取り左上
            16, 16,							//幅、高さ
            5.0f, 0.0f,						//拡大率、回転角度
            handle, true);       
        DrawRectRotaGraph(200,
            200,			//表示座標
            108 * 0, 48 * animeNum1,			//切り取り左上
            108, 48,							//幅、高さ
            3.0f, 0.0f,						//拡大率、回転角度
            Handle1, true);
        DrawRectRotaGraph(200,
            500,			//表示座標
            108 * 0, 48 * animeNum,			//切り取り左上
            108, 48,							//幅、高さ
            3.0f, 0.0f,						//拡大率、回転角度
            witchHandle, true);

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