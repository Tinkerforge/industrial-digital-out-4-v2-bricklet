Imports System
Imports System.Threading
Imports Tinkerforge

Module ExampleSimple
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your Industrial Digital Out 4 Bricklet 2.0

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim ido4 As New BrickletIndustrialDigitalOut4V2(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Set channels alternating high/low 10 times with 100 ms delay
        Dim i As Integer
        For i = 0 To 9
            Thread.Sleep(100)
            ido4.SetValue(new Boolean(){True, False, False, False})
            Thread.Sleep(100)
            ido4.SetValue(new Boolean(){False, True, False, False})
            Thread.Sleep(100)
            ido4.SetValue(new Boolean(){False, False, True, False})
            Thread.Sleep(100)
            ido4.SetValue(new Boolean(){False, False, False, True})
        Next i

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
