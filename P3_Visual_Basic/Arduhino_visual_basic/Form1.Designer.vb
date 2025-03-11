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
        Me.OFF = New System.Windows.Forms.Button()
        Me.LED1 = New System.Windows.Forms.Button()
        Me.SerialPort3 = New System.IO.Ports.SerialPort(Me.components)
        Me.LED2 = New System.Windows.Forms.Button()
        Me.LED3 = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'OFF
        '
        Me.OFF.Location = New System.Drawing.Point(504, 181)
        Me.OFF.Name = "OFF"
        Me.OFF.Size = New System.Drawing.Size(118, 23)
        Me.OFF.TabIndex = 0
        Me.OFF.Text = "LED OFF"
        Me.OFF.UseVisualStyleBackColor = True
        '
        'LED1
        '
        Me.LED1.Location = New System.Drawing.Point(193, 181)
        Me.LED1.Name = "LED1"
        Me.LED1.Size = New System.Drawing.Size(75, 23)
        Me.LED1.TabIndex = 1
        Me.LED1.Text = "LED1"
        Me.LED1.UseVisualStyleBackColor = True
        '
        'SerialPort3
        '
        Me.SerialPort3.PortName = "COM3"
        '
        'LED2
        '
        Me.LED2.Location = New System.Drawing.Point(193, 210)
        Me.LED2.Name = "LED2"
        Me.LED2.Size = New System.Drawing.Size(75, 23)
        Me.LED2.TabIndex = 2
        Me.LED2.Text = "LED2"
        Me.LED2.UseVisualStyleBackColor = True
        '
        'LED3
        '
        Me.LED3.Location = New System.Drawing.Point(193, 239)
        Me.LED3.Name = "LED3"
        Me.LED3.Size = New System.Drawing.Size(75, 23)
        Me.LED3.TabIndex = 3
        Me.LED3.Text = "LED3"
        Me.LED3.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.Controls.Add(Me.LED3)
        Me.Controls.Add(Me.LED2)
        Me.Controls.Add(Me.LED1)
        Me.Controls.Add(Me.OFF)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents OFF As Button
    Friend WithEvents LED1 As Button
    Friend WithEvents SerialPort3 As IO.Ports.SerialPort
    Friend WithEvents LED2 As Button
    Friend WithEvents LED3 As Button
End Class
