int integerReplacement(int n) {
        if(n==1) return 0;
	else if(n%2==0) return 1+integerReplacement(n/2);
	else return 2+ min(integerReplacement((n/2)+1), integerReplacement(n/2));
    }
