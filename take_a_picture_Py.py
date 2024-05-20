import serial
import struct

# Configura la conexión serial
ser = serial.Serial('COM3', 115200)  # Reemplaza 'COM3' con tu puerto serial correspondiente

# Ciclo infinito para recibir y guardar fotografías
while True:
    # Lee el tamaño del archivo de la fotografía
    file_size_bytes = ser.read(4)
    file_size = struct.unpack('<I', file_size_bytes)[0]

    # Lee los datos de la fotografía
    image_data = ser.read(file_size)

    # Guarda los datos en un archivo
    file_name = f"photo_{len([f for f in os.listdir('.') if f.startswith('photo_')])}.jpg"
    with open(file_name, 'wb') as f:
        f.write(image_data)

    print(f"Fotografía guardada como {file_name}")