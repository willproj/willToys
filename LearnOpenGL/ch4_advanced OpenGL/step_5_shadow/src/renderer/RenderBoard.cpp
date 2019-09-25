#include "renderer/RenderBoard.h"

RenderBoard::RenderBoard(const std::string& vfile, const std::string& ffile)
{
	m_Shader = std::shared_ptr<Shader>(new Shader(vfile, ffile));
	m_VBO = std::shared_ptr<VertexBuffer>(new VertexBuffer(sizeof(float) * vertices.size(), &vertices[0]));
	m_VAO = std::shared_ptr<VertexArray>(new VertexArray());
	m_VAO->AttribPointer(0, 3, 3 * 4, 0);
	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, -0.5f, 0.0f)) * glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));

}

RenderBoard::~RenderBoard()
{

}

void RenderBoard::Draw(WindowPros& windata, std::shared_ptr<Camera> camera)
{
	m_Shader->UseProgram();
	m_VAO->Bind();

	projection = glm::perspective(glm::radians(45.0f), (float)windata.m_Width / windata.m_Height, 0.1f, 100.0f);
	view = camera->GetViewMatrix();

	m_Shader->SetMat4("projection", projection);
	m_Shader->SetMat4("view", view);
	m_Shader->SetMat4("model", model);

	glDrawArrays(GL_TRIANGLES, 0, 6);

}