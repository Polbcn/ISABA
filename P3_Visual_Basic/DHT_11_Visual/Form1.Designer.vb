<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form reemplaza a Dispose para limpiar la lista de componentes.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Requerido por el Diseñador de Windows Forms
    Private components As System.ComponentModel.IContainer

    'NOTA: el Diseñador de Windows Forms necesita el siguiente procedimiento
    'Se puede modificar usando el Diseñador de Windows Forms.  
    'No lo modifique con el editor de código.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.Distancia = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.txttemp = New System.Windows.Forms.TextBox()
        Me.txthum = New System.Windows.Forms.TextBox()
        Me.SerialPort3 = New System.IO.Ports.SerialPort(Me.components)
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.LDR = New System.Windows.Forms.Label()
        Me.txtLDR = New System.Windows.Forms.TextBox()
        Me.txtDistancia = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'Distancia
        '
        Me.Distancia.AutoSize = True
        Me.Distancia.Location = New System.Drawing.Point(392, 225)
        Me.Distancia.Name = "Distancia"
        Me.Distancia.Size = New System.Drawing.Size(63, 16)
        Me.Distancia.TabIndex = 0
        Me.Distancia.Text = "Distancia"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(126, 50)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(194, 16)
        Me.Label2.TabIndex = 1
        Me.Label2.Text = "ESTACION METEOROLOGICA"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(30, 153)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(85, 16)
        Me.Label3.TabIndex = 2
        Me.Label3.Text = "Temperatura"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(30, 222)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(67, 16)
        Me.Label4.TabIndex = 3
        Me.Label4.Text = "Humedad"
        '
        'txttemp
        '
        Me.txttemp.Location = New System.Drawing.Point(170, 153)
        Me.txttemp.Name = "txttemp"
        Me.txttemp.Size = New System.Drawing.Size(100, 22)
        Me.txttemp.TabIndex = 4
        '
        'txthum
        '
        Me.txthum.Location = New System.Drawing.Point(170, 222)
        Me.txthum.Name = "txthum"
        Me.txthum.Size = New System.Drawing.Size(100, 22)
        Me.txthum.TabIndex = 5
        '
        'SerialPort3
        '
        Me.SerialPort3.PortName = "COM3"
        '
        'Timer1
        '
        Me.Timer1.Interval = 1900
        '
        'LDR
        '
        Me.LDR.AutoSize = True
        Me.LDR.Location = New System.Drawing.Point(392, 156)
        Me.LDR.Name = "LDR"
        Me.LDR.Size = New System.Drawing.Size(34, 16)
        Me.LDR.TabIndex = 6
        Me.LDR.Text = "LDR"
        '
        'txtLDR
        '
        Me.txtLDR.Location = New System.Drawing.Point(482, 156)
        Me.txtLDR.Name = "txtLDR"
        Me.txtLDR.Size = New System.Drawing.Size(100, 22)
        Me.txtLDR.TabIndex = 7
        '
        'txtDistancia
        '
        Me.txtDistancia.Location = New System.Drawing.Point(482, 225)
        Me.txtDistancia.Name = "txtDistancia"
        Me.txtDistancia.Size = New System.Drawing.Size(100, 22)
        Me.txtDistancia.TabIndex = 8
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.Controls.Add(Me.txtDistancia)
        Me.Controls.Add(Me.txtLDR)
        Me.Controls.Add(Me.LDR)
        Me.Controls.Add(Me.txthum)
        Me.Controls.Add(Me.txttemp)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Distancia)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents Distancia As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents txttemp As TextBox
    Friend WithEvents txthum As TextBox
    Friend WithEvents SerialPort3 As IO.Ports.SerialPort
    Friend WithEvents Timer1 As Timer
    Friend WithEvents LDR As Label
    Friend WithEvents txtLDR As TextBox
    Friend WithEvents txtDistancia As TextBox
End Class
