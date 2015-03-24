#include "Utils.h"
#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Draw()
{
    orbitControl.Begin();
    ofEnableDepthTest();
    
    surface.Draw();

    for (int i = entities.size() - 1; i >= 0; --i)
    {
        Entity entity = entities[i];
        entity.Draw();
    }

    mainCamera.Draw();

    ofDisableDepthTest();
    orbitControl.End();
}

void Scene::Update(float mouseX, float mouseY)
{
    surface.StartCapture();

    ofPushMatrix();
    ofTranslate(surface.fboWidth / 2, surface.fboHeight / 2, 0);

    shaderPlanet.Begin();
    shaderPlanet.Update(mouseX, mouseY);
    ofDrawPlane(0, 0, surface.fboWidth, surface.fboHeight);
    shaderPlanet.End();

    ofPopMatrix();

    surface.StopCapture();
}