for i in $(seq 1 10000000);do
	./data
	./P3514
	./answer
	if diff P3514.out answer.out ;then
		echo $i "Accepted"
	else 
		echo $i "Wrong Answer"
		exit 0
	fi
done
