void pushToStack(ShopNode* weapon, stack<ShopNode*>& stack) {
	stack.push(weapon);
}

void outputStack(stack<ShopNode*>& stack) {
	while (!stack.empty()) {
		cout << stack.top()->getName() << endl;
		stack.pop();
	}
}

void clearStack(stack<ShopNode*>& stack) {
	while (!stack.empty()) {
		stack.pop();
	}
}
