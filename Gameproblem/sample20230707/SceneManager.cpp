#include "SceneManager.h"

SceneManager::SceneManager() :
	m_runScene(kSceneKindTitle),
	m_title(),       //クラスの初期化時は()の中にコンストラクタの引数を書く
	m_main(),        //今回はどのシーンもコンストラクタで引数を要求しないので
	m_result()       //m_tutle()のような書き方でok
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
		//タイトル画面の終了チェック
		if (m_title.IsSceneEnd())
		{
			m_title.End();

			m_runScene = kSceneKindMain;
			m_main.Init();
		}
		break;

	case kSceneKindMain:
		//終了していたらSceneResultに切り替える
		if (m_main.IsSceneEnd())
		{
			//シーンを切り替える
			m_main.End();  //実行していたシーンの終了

			m_runScene = kSceneKindResult;  //次のフレーム以降、実行したいシーン
			m_result.Init();  //変更先シーンの初期化
		}
		break;
	case kSceneKindResult:
		if (m_result.IsSceneEnd())
		{
			//シーンを切り替える
			m_result.End();  //実行していたシーンの終了

			m_runScene = kSceneKindTitle;  //次のフレーム以降、実行したいシーン
			m_title.Init();  //変更先シーンの初期化
		}
		break;
	}
		//各シーンの更新を行なう
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
