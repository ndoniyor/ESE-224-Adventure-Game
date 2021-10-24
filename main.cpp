player playerConstruct(string n, int maxHp, int hp, int attackD) {
	player p1;

	p1.setName(n);
	p1.setMaxHP(maxHp);
	p1.setHP(hp);
	p1.setDMG(attackD);

	return p1;
}