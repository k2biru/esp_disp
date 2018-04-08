char pesan[50];
char serial_buf[100];
int menit, jam;

void serial_baca()
{
  unsigned int i=0;
  char menit_array[2], jam_array[2];
  //Serial.println("masuk baca");
  Serial.readString().toCharArray(serial_buf, 100); //mengambil isi serial kedalam array serial_buf
  Serial.println(serial_buf);
  if (serial_buf[0] == '#')
  {
    
    // perintah "b"========================
    if (serial_buf[1] == 'b')
    {
      buka = serial_buf[2]-48;
    } 
    // perintah "j"========================
    else if (serial_buf[1] == 'j')
    {
      menit_array[0] = serial_buf[4];
      menit_array[1] = serial_buf[5];
      jam_array[0] = serial_buf[2];
      jam_array[1] = serial_buf[3];

      menit = atoi (menit_array);
      jam = atoi (jam_array);

      sprintf(pesan, "Buka Sampai %d:%d", jam, menit);
      scrollText(pesan, 0);
    }
    // perintah "M"========================
    else if (serial_buf[1]=='M')
    {
      for(i=0;i<(strlen(serial_buf)+2);i++)
      {
        serial_buf[i-2]=serial_buf[i];
      }
      scrollText(serial_buf, 0); // integer makin kecil making cepat; kecuali 0 (default) 
    }
  }
  dataBaru=true;
}
