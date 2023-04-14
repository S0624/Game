#include "DxLib.h"
#include"Pad.h"
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
    int witchHandle = LoadGraph("../Data/Witch.png");
    //int witchAttackHandle = LoadGraph("../Data/Witch2.png");
    //int witchChargeHandle = LoadGraph("../Data/charge1.png");
    int NiwatoriRunHandle = LoadGraph("../Data/Niwatori.png");
    int nekochanAttackHandle = LoadGraph("../Data/nekochanmachine.png");
    int nekochanHandle = LoadGraph("../Data/Knight.png");

    // ダブルバッファモード
    SetDrawScreen(DX_SCREEN_BACK);

    int animeNum = 0;
    int animeFrame = 0;

    int animeMax = 8;
    int animeIndex = 0;
    while (ProcessMessage() == 0)
    {
        LONGLONG time = GetNowHiPerformanceCount();

        // 画面のクリア
        ClearDrawScreen();
        animeFrame++;
        Pad::update();
        if (animeFrame > 10)
        {
            animeNum++;
            animeFrame = 0;
        }
        if (animeNum >= animeMax)
        {
            animeNum = 0;
        }

        //int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
        //if (GetJoypadInputState(DX_INPUT_KEY_PAD1))
        //if(Pad::isPress(DX_INPUT_KEY_PAD1))
        if(Pad::isPress(DX_INPUT_PAD1))
        {
            animeIndex += 1;
            if (animeIndex > 10)
            {
                animeIndex = 0;
            }
        }

        DrawRectRotaGraph(200,
            500,			//表示座標
            48 * animeIndex, 48 * animeNum,			//切り取り左上
            48 * 1, 48,							//幅、高さ
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