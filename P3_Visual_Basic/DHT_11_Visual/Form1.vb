Public Class Form1
    Dim dato As String
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        SerialPort3.Open()
        Timer1.Enabled = True
    End Sub

    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
        Dim dato1 As String
        Dim dato2 As String
        Dim Dato3 As String
        Dim Dato4 As String

        dato = SerialPort3.ReadExisting()

        dato2 = Mid(dato, 1, 5)
        dato1 = Mid(dato, 7, 5)
        Dato3 = Mid(dato, 13, 8)
        Dato4 = Mid(dato, 20, 8)

        txttemp.Text = dato1.Trim
        txthum.Text = dato2.Trim
        txtLDR.Text = Dato3.Trim()
        txtDistancia.Text = Dato4.Trim()
    End Sub

    Private Sub LDR_Click(sender As Object, e As EventArgs) Handles LDR.Click

    End Sub
End Class
