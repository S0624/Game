#include "DxLib.h"
#include"Pad.h"
#include "math.h"
#include "game.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // window���[�h�ݒ�
    ChangeWindowMode(Game::kWindowMode);

    // �E�C���h�E���ݒ�
    SetMainWindowText("�Q�[����");

    // ��ʃT�C�Y�̐ݒ�
    SetGraphMode(Game::kScreenWindth, Game::kScreenHeight, Game::kColorDepth);

    if (DxLib_Init() == -1)        // �c�w���C�u��������������
    {
        return -1;            // �G���[���N�����璼���ɏI��
    }

    SetAlwaysRunFlag(true);
    int witchHandle = LoadGraph("../Data/Witch.png");
    //int witchAttackHandle = LoadGraph("../Data/Witch2.png");
    //int witchChargeHandle = LoadGraph("../Data/charge1.png");
    int NiwatoriRunHandle = LoadGraph("../Data/Niwatori.png");
    int nekochanAttackHandle = LoadGraph("../Data/nekochanmachine.png");
    int nekochanHandle = LoadGraph("../Data/Knight.png");

    // �_�u���o�b�t�@���[�h
    SetDrawScreen(DX_SCREEN_BACK);

    int animeNum = 0;
    int animeFrame = 0;

    int animeMax = 8;
    int animeIndex = 0;
    while (ProcessMessage() == 0)
    {
        LONGLONG time = GetNowHiPerformanceCount();

        // ��ʂ̃N���A
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
            500,			//�\�����W
            48 * animeIndex, 48 * animeNum,			//�؂��荶��
            48 * 1, 48,							//���A����
            3.0f, 0.0f,						//�g�嗦�A��]�p�x
            witchHandle, true);

        // ����ʂ�\��ʂ����ւ���
        ScreenFlip();

        // esc�L�[����������I������
        if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

        // fps��60�ɌŒ�
        while (GetNowHiPerformanceCount() - time < 16667)
        {

        }
    }

    DxLib_End();                // �c�w���C�u�����g�p�̏I������

    return 0;                // �\�t�g�̏I��
}