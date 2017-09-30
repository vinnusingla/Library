//////////////////////fermat theorem that return modular inverse of a w.r.t m/////////////////

lli powmod(lli b,lli e){
	if(e==0)return 1;
	else if(e&1)return (b*powmod(b,e-1))%MOD;
	else{
		num=powmod(b,e>>1);
		return (num*num)%MOD;
	}
}

lli fermat(lli a,lli m){
	return powmod(a,m-2);
}
