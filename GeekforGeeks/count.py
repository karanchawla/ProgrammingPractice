a = [1,2,4,2,2]
frequency = [0,0,0,0,0]
for i in range(5):
	for k in range(5):
		if a[i]==a[k] and a[i]>k:
			frequency[a[i]]+=1

print frequency
