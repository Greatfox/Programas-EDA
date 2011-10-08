Attribute VB_Name = "Module1"
Public Declare Function DLLsumar Lib "operaciones.dll"(ByVal e As Single, ByVal a As Single) As Single

Public Declare Function DLLrestar Lib "operaciones.dll" (ByVal e As Single, ByVal a As Single) As Single

Public Declare Function DLLmultiplicar Lib "operaciones.dll" (ByVal e As Single, ByVal a As Single) As Single

Public Declare Function DLLdividir Lib "operaciones.dll" (ByVal e As Single, ByVal a As Single) As Single
