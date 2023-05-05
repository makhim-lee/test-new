#fahr --> celsius


fahr = int(input("fahr : "))

celsius = 5 / 9 * (fahr - 32)
#print("fahr : " , fahr, "celsius : ", celsius)
#print("fahr : %d  ---  celsius : %.2f"%(fahr, celsius))
#print("fahr : {:3d} --- celsius : {}:.2f}".format(fahr, celsius))
print(f"fahr : {fahr:3d} --- celsius : {celsius:.2f}")
