Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles OFF.Click
        SerialPort3.Write("0")
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        SerialPort3.Open()

    End Sub

    Private Sub LED1_Click(sender As Object, e As EventArgs) Handles LED1.Click
        SerialPort3.Write("1")
    End Sub

    Private Sub LED2_Click(sender As Object, e As EventArgs) Handles LED2.Click
        SerialPort3.Write("2")
    End Sub
    Private Sub LED3_Click(sender As Object, e As EventArgs) Handles LED3.Click
        SerialPort3.Write("3")
    End Sub
End Class
