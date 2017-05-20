
def calc(snakelist, minLength):
	snakelist.sort()
	counter = snakelist[:]
	x = 0
	C = len(snakelist)	
	if sum(snakelist) < minLength:
			print("0")
	else:
		while x < C:
			if snakelist[x] < minLength:
				del snakelist[x]
				snakelist[x] += 1
			else:
				break
		print(len(snakelist))
		
def main():
	
	for _ in range(int(input())):
		n,q = input().strip().split(' ')
		n,q = [int(n),int(q)]
		snakelist = list(map(int, input().strip().split()))
		for x in range(q):
			Q1 = int(input())
			calc(snakelist,Q1)
			

if __name__ == '__main__':
	main()
