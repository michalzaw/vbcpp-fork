set (GUI_SOURCES
	GUI/FontLoader.cpp
	GUI/GUIManager.cpp
	GUI/GUIObject.cpp
	GUI/GUIRenderListElement.cpp
	GUI/Image.cpp
	GUI/Label.cpp
)

set (GUI_HEADERS 
	GUI/FontLoader.h
	GUI/GUIManager.h
	GUI/GUIObject.h
	GUI/GUIRenderListElement.h
	GUI/Image.h
	GUI/Label.h
)

set (GUI_SOURCES ${GUI_SOURCES} PARENT_SCOPE)
set (GUI_HEADERS ${GUI_HEADERS} PARENT_SCOPE)