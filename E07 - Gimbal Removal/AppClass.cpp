#include "AppClass.h"
void Application::InitVariables(void)
{
	////Change this to your name and email
	m_sProgrammer = "Alberto Bobadilla - labigm@rit.edu";
	vector3 v3Position(0.0f, 0.0f, 10.0f);
	vector3 v3Target = ZERO_V3;
	vector3 v3Upward = AXIS_Y;
	m_pCameraMngr->SetPositionTargetAndUpward(v3Position, v3Target, v3Upward);
	m_pModelMngr->LoadModel(m_sSteve);
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();

	//Update Entity Manager
	m_pEntityMngr->Update();

	//Add objects to render list
	m_pEntityMngr->AddEntityToRenderList(-1, true);
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();

	m_qOrientation *= quaternion(glm::angleAxis(glm::radians(m_v3Rotation.x), AXIS_X));
	m_qOrientation *= quaternion(glm::angleAxis(glm::radians(m_v3Rotation.y), AXIS_Y));
	m_qOrientation *= quaternion(glm::angleAxis(glm::radians(m_v3Rotation.z), AXIS_Z));

	m_v3Rotation = vector3(0.0f);

	/*
	* The following line was replaced by the model manager so we can see a model instead of a cone
	*/
	//m_pMesh->Render(m4Projection, m4View, ToMatrix4(m_m4Model));
	m_pModelMngr->AddModelToRenderList(m_sSteve, ToMatrix4(m_qOrientation));


	// draw a skybox
	m_pModelMngr->AddSkyboxToRenderList();

	//render list call
	m_uRenderCallCount = m_pModelMngr->Render();

	//clear the render list
	m_pModelMngr->ClearRenderList();

	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//release GUI
	ShutdownGUI();
}