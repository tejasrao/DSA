a = [1,2,3,4,5,6,7,8,9,10]
n = 7
d = {i:0 for i in a}
i = d.popitem()[0]
while len(d.keys()) > 0:
	if (n-i) in d:
		print(n - i, i)
		d.pop(n -i)
	i = d.popitem()[0]
