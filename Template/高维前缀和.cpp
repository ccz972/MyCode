/*
sum[i]表示i的所有子集的状态和，同理可以应用于max min
for (int j = 0; j < 20; j ++ ) {
  for (int i = 0; i < 1 << 20; i ++ ) if (i >> j & 1) {
    sum[i] += sum[i ^ (1 << j)];
  }
}
*/

