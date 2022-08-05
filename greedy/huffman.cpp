
// a huffman tree
struct Node {
	// input charcters
	char data;
	unsigned freq; // freq of character
	Node *left, *right;

	Node(char data, unsigned freq, Node* l = NULL, Node* r = NULL)
	{

		this->left = l;
		this->right = r;
		this->data = data;
		this->freq = freq;
	}
}

struct compare()  {
	bool operator()(Node* l, Node* r) {
		return (l->freq > r->freq);
	}
};

void printCodes (Node* root, string str) {
	if (!root) return;
	if (root->data != '$')
		cout << root->data << ": " << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}
// build huffman tree
// print codes for the character
void printHcode(char *arr, int *freq, int size) {
	priority_queue<Node*, vector<Node*>, compare> h;
	for (int i = 0; i < n; ++i)
		h.push(new Node(arr[i], freq[i]));

	while (h.size() > 1) {
		// Extract the two minimum
		// freq items from min heap
		Node *l = h.top();
		h.pop();
		Node *r = h.top();
		h.pop();

		// Create a new internal node with
		// frequency equal to the sum of the
		// two nodes frequencies. Make the
		// two extracted node as left and right children
		// of this new node. Add this node
		// to the min heap '$' is a special value
		// for internal nodes, not used

		Node *top = new Node('$', l->freq + r->freq, l, r);
		h.push(top);
	}


	// Print Huffman codes using
	// the Huffman tree built above
	printCodes(h.top(), "");
}
int main() {

    char arr[] = { 'a', 'd', 'e', 'f' };
	int freq[] = { 30, 40, 80, 60 };

	int size = sizeof(arr) / sizeof(arr[0]);

	printHcodes(arr, freq, size);

	return 0;
}