#pragma once
#include "..//event/MouseEvent.h"


namespace gltoys::utils
{
	enum MouseButton
	{
		LEFT_BUTTON,
		RIGHT_BUTTON,
		MIDDLE_BUTTON
	};

	class Mouse
	{
	private:
		bool m_LeftButton = false;
		bool m_RightButton = false;
		bool m_MiddleButton = true;

		glm::vec2 m_CurrentPosition = glm::vec2(0.0f);
		glm::vec2 m_LastPosition = glm::vec2(0.0f);
		glm::vec2 m_ScrollOffset = glm::vec2(0.1f);

		float m_ScrollSensitivity = 0.45f;
		float m_MouseSensitivity = 0.1;


		static Mouse s_Mouse;
		Mouse();
	public:
		~Mouse();
		static Mouse& Get();

		static Mouse& GetMouseInstance() { return s_Mouse; }

		glm::vec2& GetMouseLastPosition() { return m_LastPosition; }

		glm::vec2& GetMouseCurrentPosition() { return m_CurrentPosition; }

		glm::vec2& GetMouseScrollOffset() { return m_ScrollOffset; }

		float GetMouseSensitivity()const { return m_MouseSensitivity; }

		float GetScrollSensitivity()const { return m_ScrollSensitivity; }

		bool IsLeftMousebuttonPressed()const { return m_LeftButton; }

		bool IsRightMousebuttonPressed()const { return m_RightButton; }

		bool IsMiddleMousebuttonMoved()const { return m_MiddleButton; }

		void OnEvent(events::MouseMovedEvent& event);

		void OnEvent(events::MousePressedEvent& event);

		void OnEvent(events::MouseRelasedEvent& event);

		void OnEvent(events::MouseScrollEvent& event);

		void UpdateMouse();

	};
}