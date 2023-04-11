#include "DxLib.h"

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
    //int witchHandle = LoadGraph("../Data/Witch.png");
    int witchAttackHandle = LoadGraph("../Data/Witch2.png");
    int witchChargeHandle = LoadGraph("../Data/charge1.png");
    int NiwatoriRunHandle = LoadGraph("../Data/Niwatori.png");
    int nekochanAttackHandle = LoadGraph("../Data/nekochanmachine.png");
    int nekochanHandle = LoadGraph("../Data/Knight.png");

    // �_�u���o�b�t�@���[�h
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

        // ��ʂ̃N���A
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
            600,			//�\�����W
            16 * 0, 16 * animeNum2,			//�؂��荶��
            16, 16,							//���A����
            3.0f, 0.0f,						//�g�嗦�A��]�p�x
            nekochanHandle, true);
        DrawRectRotaGraph(posX,
            100,			//�\�����W
            32 * 0, 32 * animeNum3,			//�؂��荶��
            32, 32,							//���A����
            3.0f, 0.0f,						//�g�嗦�A��]�p�x
            NiwatoriRunHandle, true);
        DrawRectRotaGraph(100,
            400,			//�\�����W
            48 * 0, 32 * animeNum4,			//�؂��荶��
            48, 32,							//���A����
            3.0f, 0.0f,						//�g�嗦�A��]�p�x
            nekochanAttackHandle, true);       
        DrawRectRotaGraph(200,
            200,			//�\�����W
            108 * 0, 48 * animeNum1,			//�؂��荶��
            108, 48,							//���A����
            3.0f, 0.0f,						//�g�嗦�A��]�p�x
            witchChargeHandle, true);
        DrawRectRotaGraph(200,
            500,			//�\�����W
            108 * 0, 48 * animeNum,			//�؂��荶��
            108, 48,							//���A����
            3.0f, 0.0f,						//�g�嗦�A��]�p�x
            witchAttackHandle, true);

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