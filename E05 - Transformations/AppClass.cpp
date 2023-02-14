#include "AppClass.h"
void Application::InitVariables(void)
{
	////Change this to your name and email
	m_sProgrammer = "Alberto Bobadilla - labigm@rit.edu";
	vector3 v3Position(0.0f, 0.0f, 10.0f);
	vector3 v3Target = ZERO_V3;
	vector3 v3Upward = AXIS_Y;
	m_pCameraMngr->SetPositionTargetAndUpward(v3Position, v3Target, v3Upward);

	//Allocate the memory for the Meshes
	m_uMeshCount = 46;
	for (int i = 0; i < m_uMeshCount; i++)
	{
		MyMesh* m_pMesh = new MyMesh();
		m_pMeshList.push_back(m_pMesh);
		m_pMeshList[i]->GenerateCube(1.0, C_BLACK);
	}
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

	//Calculate the model, view and projection matrix
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();

	// Timer for moving cubes
	static float fTimer = 0;
	static uint uClock = m_pSystem->GenClock();
	fTimer += m_pSystem->GetDeltaTime(uClock);

	// Vector3 that gets changed by timer, to change the position matrix
	static vector3 v3ChangeInPos = vector3(0.0f, 0.0f, 0.0f);
	v3ChangeInPos.x += fTimer;

	// Position matrix
	matrix4 m4Position = glm::translate(vector3(-30.0f, 0.0f, 0.0f)) * glm::translate(v3ChangeInPos);

	// REPLICATE SCENE
	// First row (from bottom)
	m_pMeshList[0]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(3.0f, 0.0f, 0.0f)));
	m_pMeshList[1]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(4.0f, 0.0f, 0.0f)));
	m_pMeshList[2]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(6.0f, 0.0f, 0.0f)));
	m_pMeshList[3]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(7.0f, 0.0f, 0.0f)));
	// Second row
	m_pMeshList[4]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(0.0f, 1.0f, 0.0f)));
	m_pMeshList[5]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(2.0f, 1.0f, 0.0f)));
	m_pMeshList[6]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8.0f, 1.0f, 0.0f)));
	m_pMeshList[7]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(10.0f, 1.0f, 0.0f)));
	// Third row
	m_pMeshList[8]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(0.0f, 2.0f, 0.0f)));
	m_pMeshList[9]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(2.0f, 2.0f, 0.0f)));
	m_pMeshList[10]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(3.0f, 2.0f, 0.0f)));
	m_pMeshList[11]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(4.0f, 2.0f, 0.0f)));
	m_pMeshList[12]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(5.0f, 2.0f, 0.0f)));
	m_pMeshList[13]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(6.0f, 2.0f, 0.0f)));
	m_pMeshList[14]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(7.0f, 2.0f, 0.0f)));
	m_pMeshList[15]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8.0f, 2.0f, 0.0f)));
	m_pMeshList[16]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(10.0f, 2.0f, 0.0f)));
	// Fourth row
	m_pMeshList[17]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(0.0f, 3.0f, 0.0f)));
	m_pMeshList[18]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(1.0f, 3.0f, 0.0f)));
	m_pMeshList[19]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(2.0f, 3.0f, 0.0f)));
	m_pMeshList[20]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(3.0f, 3.0f, 0.0f)));
	m_pMeshList[21]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(4.0f, 3.0f, 0.0f)));
	m_pMeshList[22]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(5.0f, 3.0f, 0.0f)));
	m_pMeshList[23]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(6.0f, 3.0f, 0.0f)));
	m_pMeshList[24]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(7.0f, 3.0f, 0.0f)));
	m_pMeshList[25]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8.0f, 3.0f, 0.0f)));
	m_pMeshList[26]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(9.0f, 3.0f, 0.0f)));
	m_pMeshList[27]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(10.0f, 3.0f, 0.0f)));
	// Fifth row
	m_pMeshList[28]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(1.0f, 4.0f, 0.0f)));
	m_pMeshList[29]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(2.0f, 4.0f, 0.0f)));
	m_pMeshList[30]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(4.0f, 4.0f, 0.0f)));
	m_pMeshList[31]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(5.0f, 4.0f, 0.0f)));
	m_pMeshList[32]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(6.0f, 4.0f, 0.0f)));
	m_pMeshList[33]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8.0f, 4.0f, 0.0f)));
	m_pMeshList[34]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(9.0f, 4.0f, 0.0f)));
	// Sixth row
	m_pMeshList[35]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(2.0f, 5.0f, 0.0f)));
	m_pMeshList[36]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(3.0f, 5.0f, 0.0f)));
	m_pMeshList[37]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(4.0f, 5.0f, 0.0f)));
	m_pMeshList[38]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(5.0f, 5.0f, 0.0f)));
	m_pMeshList[39]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(6.0f, 5.0f, 0.0f)));
	m_pMeshList[40]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(7.0f, 5.0f, 0.0f)));
	m_pMeshList[41]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8.0f, 5.0f, 0.0f)));
	// Seventh row
	m_pMeshList[42]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(3.0f, 6.0f, 0.0f)));
	m_pMeshList[43]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(7.0f, 6.0f, 0.0f)));
	// Eigth row
	m_pMeshList[44]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(2.0f, 7.0f, 0.0f)));
	m_pMeshList[45]->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8.0f, 7.0f, 0.0f)));

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
	//Release meshes
	for (int i = 0; i < m_uMeshCount; i++) {
		SafeDelete(m_pMeshList[i]);
	}

	//release GUI
	ShutdownGUI();
}