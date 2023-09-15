#include "SceneManager.h"

SceneManager::SceneManager() :
	m_runScene(kSceneKindTitle),
	m_title(),       //�N���X�̏���������()�̒��ɃR���X�g���N�^�̈���������
	m_main(),        //����͂ǂ̃V�[�����R���X�g���N�^�ň�����v�����Ȃ��̂�
	m_result()       //m_tutle()�̂悤�ȏ�������ok
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
	switch (m_runScene)
	{
	case kSceneKindTitle:
		m_title.Init();
		break;
	case kSceneKindMain:
		m_main.Init();
		break;
	case kSceneKindResult:
		m_result.Init();
		break;
	default:
		break;
	}
}

void SceneManager::Update()
{

	switch (m_runScene)
	{
	case kSceneKindTitle:
		//�^�C�g����ʂ̏I���`�F�b�N
		if (m_title.IsSceneEnd())
		{
			m_title.End();

			m_runScene = kSceneKindMain;
			m_main.Init();
		}
		break;

	case kSceneKindMain:
		//�I�����Ă�����SceneResult�ɐ؂�ւ���
		if (m_main.IsSceneEnd())
		{
			//�V�[����؂�ւ���
			m_main.End();  //���s���Ă����V�[���̏I��

			m_runScene = kSceneKindResult;  //���̃t���[���ȍ~�A���s�������V�[��
			m_result.Init();  //�ύX��V�[���̏�����
		}
		break;
	case kSceneKindResult:
		if (m_result.IsSceneEnd())
		{
			//�V�[����؂�ւ���
			m_result.End();  //���s���Ă����V�[���̏I��

			m_runScene = kSceneKindTitle;  //���̃t���[���ȍ~�A���s�������V�[��
			m_title.Init();  //�ύX��V�[���̏�����
		}
		break;
	}
		//�e�V�[���̍X�V���s�Ȃ�
		switch (m_runScene)
		{
		case kSceneKindTitle:
			m_title.Update();
			break;
		case kSceneKindMain:
			m_main.Update();
			break;
		case kSceneKindResult:
			m_result.Update();
			break;
		default:
			break;
		}
}

void SceneManager::Draw()
{
	switch (m_runScene)
	{
	case kSceneKindTitle:
		m_title.Draw();
		break;
	case kSceneKindMain:
		m_main.Draw();
		break;
	case kSceneKindResult:
		m_result.Draw();
		break;
	default:
		break;
	}
}

void SceneManager::End()
{
	switch (m_runScene)
	{
	case kSceneKindTitle:
		m_title.End();
		break;
	case kSceneKindMain:
		m_main.End();
		break;
	case kSceneKindResult:
		m_result.End();
		break;
	default:
		break;
	}
}
