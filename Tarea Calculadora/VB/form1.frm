VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5850
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4110
   LinkTopic       =   "Form1"
   ScaleHeight     =   5850
   ScaleWidth      =   4110
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton salir 
      Caption         =   "S&alir"
      Height          =   615
      Left            =   1200
      TabIndex        =   10
      Top             =   4920
      Width           =   1335
   End
   Begin VB.CommandButton dividir 
      Caption         =   "&Dividir"
      Height          =   495
      Left            =   2280
      TabIndex        =   9
      Top             =   4080
      Width           =   1455
   End
   Begin VB.CommandButton multiplicar 
      Caption         =   "&Multiplicar"
      Height          =   375
      Left            =   240
      TabIndex        =   8
      Top             =   4200
      Width           =   1455
   End
   Begin VB.CommandButton restar 
      Caption         =   "&Restar"
      Height          =   495
      Left            =   2160
      TabIndex        =   7
      Top             =   3240
      Width           =   1575
   End
   Begin VB.CommandButton sumar 
      Caption         =   "&Sumar"
      Height          =   495
      Left            =   240
      TabIndex        =   6
      Top             =   3240
      Width           =   1455
   End
   Begin VB.TextBox num3 
      Height          =   375
      Left            =   2040
      TabIndex        =   5
      Top             =   1920
      Width           =   1695
   End
   Begin VB.TextBox num2 
      Height          =   375
      Left            =   2040
      TabIndex        =   4
      Top             =   1200
      Width           =   1695
   End
   Begin VB.TextBox num1 
      Height          =   375
      Left            =   2040
      TabIndex        =   3
      Top             =   480
      Width           =   1695
   End
   Begin VB.Label Label3 
      Caption         =   "Resultado"
      Height          =   375
      Left            =   240
      TabIndex        =   2
      Top             =   1920
      Width           =   1695
   End
   Begin VB.Label Label2 
      Caption         =   "Numero 2:"
      Height          =   375
      Left            =   240
      TabIndex        =   1
      Top             =   1200
      Width           =   1695
   End
   Begin VB.Label Label1 
      Caption         =   "Numero 1:"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   480
      Width           =   1575
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub salir_Click()
End
End Sub

Private Sub sumar_Click()
num3 = DLLsumar(num1, num2)
End Sub

Private Sub restar_Click()
num3 = DLLrestar(num1, num2)
End Sub

Private Sub multiplicar_Click()
num3 = DLLmultiplicar(num1, num2)
End Sub

Private Sub dividir_Click()
num3 = DLLdividir(num1, num2)
End Sub
