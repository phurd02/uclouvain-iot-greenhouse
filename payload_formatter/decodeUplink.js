function decodeUplink(input) {
  var data = {};
  data.temperature = ((input.bytes[0] << 8) + input.bytes[1])/100;
  data.humidity = ((input.bytes[2] << 8) + input.bytes[3])/100;
  data.pressure = ((input.bytes[4] << 8) + input.bytes[5])/100;
  data.spectral_A = ((input.bytes[6] << 8) + input.bytes[7])/100;
  data.spectral_B = ((input.bytes[8] << 8) + input.bytes[9])/100;
  data.spectral_C = ((input.bytes[10] << 8) + input.bytes[11])/100;
  data.spectral_D = ((input.bytes[12] << 8) + input.bytes[13])/100;
  data.spectral_E = ((input.bytes[14] << 8) + input.bytes[15])/100;
  data.spectral_F = ((input.bytes[16] << 8) + input.bytes[17])/100;
  data.spectral_G = ((input.bytes[18] << 8) + input.bytes[19])/100;
  data.spectral_H = ((input.bytes[20] << 8) + input.bytes[21])/100;
  data.spectral_R = ((input.bytes[22] << 8) + input.bytes[23])/100;
  data.spectral_I = ((input.bytes[24] << 8) + input.bytes[25])/100;
  data.spectral_S = ((input.bytes[26] << 8) + input.bytes[27])/100;
  data.spectral_J = ((input.bytes[28] << 8) + input.bytes[29])/100;
  data.spectral_T = ((input.bytes[30] << 8) + input.bytes[31])/100;
  data.spectral_U = ((input.bytes[32] << 8) + input.bytes[33])/100;
  data.spectral_V = ((input.bytes[34] << 8) + input.bytes[35])/100;
  data.spectral_W = ((input.bytes[36] << 8) + input.bytes[37])/100;
  data.spectral_K = ((input.bytes[38] << 8) + input.bytes[39])/100;
  data.spectral_L = ((input.bytes[40] << 8) + input.bytes[41])/100;
  data.battery = ((input.bytes[42] << 8) + input.bytes[43]);
  return {
    data: data
  };
}

