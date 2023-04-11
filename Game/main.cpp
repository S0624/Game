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

    SetAlwaysRunFlag(true);
    //int witchHandle = LoadGraph("../Data/Witch.png");
    int witchAttackHandle = LoadGraph("../Data/Witch2.png");
    int witchChargeHandle = LoadGraph("../Data/charge1.png");
    int NiwatoriRunHandle = LoadGraph("../Data/Niwatori.png");
    int nekochanAttackHandle = LoadGraph("../Data/nekochanmachine.png");
    int nekochanHandle = LoadGraph("../Data/Knight.png");

    // ダブルバッファモード
    SetDrawScreen(DX_SCREEN_BACK);

    int animeNum = 0;
    int animeNum1 = 0;
    int animeNum2 = 0;
    int animeNum3 = 0;
    int animeNum4 = 0;
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
            animeNum3++;
            animeNum4++;
            posX += 30;
            animeFrame = 0;
        }
        if (animeNum3 >= 10)
        {
            animeNum3 = 0;
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
        if (animeNum4 >= 4)
        {
            animeNum4 = 0;
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
            3.0f, 0.0f,						//拡大率、回転角度
            nekochanHandle, true);
        DrawRectRotaGraph(posX,
            100,			//表示座標
            32 * 0, 32 * animeNum3,			//切り取り左上
            32, 32,							//幅、高さ
            3.0f, 0.0f,						//拡大率、回転角度
            NiwatoriRunHandle, true);
        DrawRectRotaGraph(100,
            400,			//表示座標
            48 * 0, 32 * animeNum4,			//切り取り左上
            48, 32,							//幅、高さ
            3.0f, 0.0f,						//拡大率、回転角度
            nekochanAttackHandle, true);       
        DrawRectRotaGraph(200,
            200,			//表示座標
            108 * 0, 48 * animeNum1,			//切り取り左上
            108, 48,							//幅、高さ
            3.0f, 0.0f,						//拡大率、回転角度
            witchChargeHandle, true);
        DrawRectRotaGraph(200,
            500,			//表示座標
            108 * 0, 48 * animeNum,			//切り取り左上
            108, 48,							//幅、高さ
            3.0f, 0.0f,						//拡大率、回転角度
            witchAttackHandle, true);

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