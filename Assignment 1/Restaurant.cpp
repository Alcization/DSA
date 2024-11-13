#include "main.h"

int abs(int number) // Lấy giá trị tuyệt đối
{
	return (number < 0) ? ((-1)*number) : number;
}


class imp_res : public Restaurant
{
	class customerTime;
private:
	customer* customerQueueHead; //! lưu vị trí đầu tiên của khách hàng trong queue
	customer* customerQueueTail; //! lưu vị trí cuối cùng của khách hàng trong queue
	customer* customerX; //! lưu vị trí của khách hàng vừa cập nhật trong bàn ăn

	int sizeCustomerInDesk; //! số lượng khách hàng trong bàn ăn
	int sizeCustomerQueue; //! số lượng khách hàng trong hàng chờ

	customerTime* CustomerTimeHead; //! khách hàng đầu tiên tới nhà hàng
	customerTime* CustomerTimeTail; //! khách hàng cuối cùng tới nhà hàng

private:

public:	
	imp_res() {
		customerX = customerQueueHead = customerQueueTail =  nullptr;
		sizeCustomerQueue = sizeCustomerInDesk = 0;
		CustomerTimeHead = CustomerTimeTail = nullptr;
	};
	void RED(string name, int energy);
	void BLUE(int num);
	void PURPLE();
	void REVERSAL();
	void DOMAIN_EXPANSION();
	void UNLIMITED_VOID();
	void LIGHT(int num);
	int inssort2(customer* A, int n, int incr);
	customer* getCustomerAt(customer* head, int n){
		for (int i = 0; i < n; i++) head = head->next;
		return head;
	}
	~imp_res(){
		while (CustomerTimeHead != nullptr)
		{
			customerTime* temp = CustomerTimeHead->next;
			delete CustomerTimeHead;
			CustomerTimeHead = temp;
		}
		
	}
private:
	class customerTime
	{
	public:
		customer* data; //! vị trí của khách này trong nhà hàng gồm tên, năng lượng,...
		customerTime* next; //! khách đến sau
		customerTime* prev; //! khách đến trước
		bool inDisk; //! xem có ngồi trong bàn hay không
	public:
		customerTime(customer * data, bool inDisk, customerTime* next = nullptr, customerTime* prev = nullptr)
		:data(data),next(next),prev(prev), inDisk(inDisk) {}
		~customerTime(){}
	};

};

void imp_res::RED(string name, int energy)
{
	
	// Đuổi khách nếu không phải thuật sư hay oán linh
	if(energy == 0) return;
	// Đuổi khách nếu hàng chờ đã đầy
	else if(sizeCustomerQueue >= MAXSIZE) return; // Work in Progress
	// "Thiên thượng thiên hạ, duy ngã độc tôn" : Kiểm tra khách có trùng tên hay không
	else
	{
		if (CustomerTimeHead != nullptr)
		{
			customerTime* temp = CustomerTimeHead;
			for(int i = 0; i < sizeCustomerInDesk + sizeCustomerQueue; i++)
			{		
				if (temp->data->name == name) return;
				temp = temp->next;
			}	
			temp = nullptr;
		}
	}
	// Nếu bàn đã đầy cho khách vào hàng chờ
	//^ chú ý này đang quản lí trong hàng chờ sử dụng customerQueueHead
	if(sizeCustomerInDesk == MAXSIZE)
	{
		customer* newCustomer = new customer(name, energy, nullptr, nullptr);
		//& thì ra trong hàng chờ không có nào đứng nên mày đứng 1 mình đi 
		if(sizeCustomerQueue == 0)
		{
			//TODO cập nhật thằng mới vô này là danh sách liên kết vòng đôi trong hàng chờ cần cập nhật prev và next
			customerQueueHead = customerQueueTail = newCustomer;
			customerQueueHead->next = customerQueueTail;
		}
		//* task4 chèn cuối danh sách liên kết đôi vòng
		//& thì ra hàng chờ đang đông cho mày xuống cuối hàng đứng hộ tao
		else{
			//TODO thêm vào sau khách hàng đầu tiên (thêm vào cuối) dùng next
			customerQueueTail->next = newCustomer;
			customerQueueTail = newCustomer;
		}
		//& cập nhật số lượng khách nhà hàng
		sizeCustomerQueue ++;

		//^biến quản lý thời gian khách hàng nào đến trước giống như 1 sổ kí lưu vị trí khách hàng
		//& ghi nó vào danh sách để còn tính tiền nó trốn nữa
		customerTime* newCustomerTime = new customerTime (newCustomer, false);  
		//TODO thêm khách hàng mới vô vào danh sách CustomerTime này đang dùng danh sách liên kết đôi
		CustomerTimeTail->next = newCustomerTime;
		newCustomerTime->prev = CustomerTimeTail;
		CustomerTimeTail = newCustomerTime;
		return;
	}
	//* Bước 5 khách hàng đầu tiên vào nhà hàng này là danh sách liên kết đôi vòng
	//* giá trị next = prev = chính nó và cập nhật sizeCustomerInDesk
	//& thì ra khách hàng mở bát đầu tiên nhà hàng
	//^ chú ý này đang quản lí trong hàng chờ sử dụng customerX
	else if(sizeCustomerInDesk == 0)
	{	
		//& đưa đại ka tới một chỗ bất kì ngồi
		customerX = new customer (name, energy, nullptr, nullptr);  
		//TODO cập nhật thằng mới vô này là danh sách liên kết vòng đôi trong bàn ăn cần cập nhật prev và next
		customerX->next = customerX;
		customerX->prev = customerX;
		//^ biến quản lý thời gian khách hàng nào đến trước giống như 1 sổ kí lưu vị trí khách hàng
		//& ghi nó vào danh sách để còn tính tiền nó trốn nữa
		CustomerTimeTail = CustomerTimeHead = new customerTime (customerX, true);  
		sizeCustomerInDesk++;
		return;
	}

	//* Bước 6 nếu TH mà sizeCustomerInDesk >= MAXSIZE / 2.0 ta phải tìm vị trí mới của customerX
	//* tìm vị trí mới đễ dễ dàng insert customer mới
	//
	if(sizeCustomerInDesk >= MAXSIZE / 2.0)
	{
		//* tìm kiếm khách hàng customerX dùng for để tìm giá trị lớn nhất dựa trên sizeCustomerInDesk
		//* customerX sẽ lưu vị trí lớn nhất
		//& nhà hàng đông quá mất tích thằng lên món đầu tiên rồi thôi tìm thằng có trị tuyệt đối hiện năng lượng lớn nhất
		//& tìm được nó mới thêm thằng nhót nảy hàng chờ chứ thêm nó vô đại mấy anh kia đấm nữa
		customer* temp = customerX;
		for(int i = 0; i < sizeCustomerInDesk; i++)
		{
			//& thằng này đang có trị tuyệt đối enery lớn hơn nè mà duyệt đến cuối xem nào lớn hơn nữa không
			//TODO tìm thằng có năng lượng có độ chênh lệch sức mạng so với thằng mới vô
			if (abs(energy - temp->energy) > abs(energy - customerX->energy)) customerX = temp;
			temp = temp->next; 
			//& Tìm được thằng lên món đầu tiên thôi (customerX) tìm hơi mệt nha
		}
	}
	customer* newCustomer = new customer (name, energy, nullptr, nullptr); 
	
	//* Bước 7 trường hợp chèn theo chiều kim đồng hồ
	if(energy >= customerX->energy)
	{
		//TODO thêm vào sau khách hàng theo chiều kim đồng hồ dùng next
		newCustomer->next = customerX->next;
		customerX->next = newCustomer;
		newCustomer->prev = customerX;
		newCustomer->next->prev = newCustomer;
	}
	//* Bước 7 trương hợp chèn ngược chiều kim đồng hồ
	else
	{
		//TODO thêm vào trước khách hàng dùng prev
		newCustomer->prev = customerX->prev;
		customerX->prev = newCustomer;
		newCustomer->next = customerX;
		newCustomer->prev->next = newCustomer;
	}

	//& lên món cho anh mới vô nào đưa ảnh thành khách hàng X
	customerX = newCustomer;
	//& cập nhật số lượng khách trong bàn bàn
	sizeCustomerInDesk++;

	//^biến quản lý thời gian khách hàng nào đến trước giống như 1 sổ kí lưu vị trí khách hàng
	//& ghi nó vào danh sách để còn tính tiền nó trốn nữa
	customerTime* newCustomerTime = new customerTime (customerX, true);
	//TODO thêm khách hàng mới vô vào danh sách CustomerTime này đang dùng danh sách liên kết đôi
	CustomerTimeTail->next = newCustomerTime;
	newCustomerTime->prev = CustomerTimeTail;
	CustomerTimeTail = newCustomerTime;
	return;
}

void imp_res::BLUE(int num)
{	
	if (sizeCustomerInDesk == 0) return;
	// Đuổi num khách 
	for (int i = 0; i < num and sizeCustomerInDesk != 0; i++)
	{	
		// B1 : Tìm khách cần đuổi về
		customerTime* customerTimeDelete = CustomerTimeHead;
		while (customerTimeDelete->inDisk == false) customerTimeDelete = customerTimeDelete->next;
		// B2 : Đuổi khách 
		if (customerTimeDelete == CustomerTimeHead) CustomerTimeHead = CustomerTimeHead->next;
		if (customerTimeDelete == CustomerTimeTail) CustomerTimeTail = CustomerTimeTail->prev;
		if (customerTimeDelete->prev != nullptr) customerTimeDelete->prev->next = customerTimeDelete->next;
		if (customerTimeDelete->next != nullptr) customerTimeDelete->next->prev = customerTimeDelete->prev;
		if (customerTimeDelete->data->energy > 0) customerX = customerTimeDelete->data->next;
		else customerX = customerTimeDelete->data->prev;
		customerTimeDelete->data->prev->next = customerTimeDelete->data->next;
		customerTimeDelete->data->next->prev = customerTimeDelete->data->prev;
		delete customerTimeDelete->data; // Warning?
		delete customerTimeDelete;
		customerTimeDelete->data = nullptr;
		customerTimeDelete = nullptr;
		sizeCustomerInDesk--;
	}





	for (int i = 0; i < num and sizeCustomerQueue != 0 and sizeCustomerInDesk != MAXSIZE; i++)
	{
		customer* newCustomer = customerQueueHead;
		customerQueueHead = customerQueueHead->next;
		sizeCustomerQueue--;
		// Thêm khách vào bàn
		if(sizeCustomerInDesk == 0)
		{
			//& đưa đại ka tới một chỗ bất kì ngồi
			customerX = newCustomer; 
			//TODO cập nhật thằng mới vô này là danh sách liên kết vòng đôi trong bàn ăn cần cập nhật prev và next
			customerX->next = customerX;
			customerX->prev = customerX;
		}
		else
		{
			if(sizeCustomerInDesk >= MAXSIZE / 2.0)
			{
				//* tìm kiếm khách hàng customerX dùng for để tìm giá trị lớn nhất dựa trên sizeCustomerInDesk
				//* customerX sẽ lưu vị trí lớn nhất
				//& nhà hàng đông quá mất tích thằng lên món đầu tiên rồi thôi tìm thằng có trị tuyệt đối hiện năng lượng lớn nhất
				//& tìm được nó mới thêm thằng nhót nảy hàng chờ chứ thêm nó vô đại mấy anh kia đấm nữa
				customer* temp = customerX;
				for(int i = 0; i < sizeCustomerInDesk; i++)
				{
					//& thằng này đang có trị tuyệt đối enery lớn hơn nè mà duyệt đến cuối xem nào lớn hơn nữa không
					//TODO tìm thằng có năng lượng có độ chênh lệch sức mạng so với thằng mới vô
					if (abs(newCustomer->energy - temp->energy) > abs(newCustomer->energy - customerX->energy)) customerX = temp;
					temp = temp->next; 
					//& Tìm được thằng lên món đầu tiên thôi (customerX) tìm hơi mệt nha
				}
			}

			//* Bước 7 trường hợp chèn theo chiều kim đồng hồ
			if(newCustomer->energy >= customerX->energy)
			{
			//TODO thêm vào sau khách hàng theo chiều kim đồng hồ dùng next
				newCustomer->next = customerX->next;
				customerX->next = newCustomer;
				newCustomer->prev = customerX;
				newCustomer->next->prev = newCustomer;
			}
			//* Bước 7 trương hợp chèn ngược chiều kim đồng hồ
			else
			{
			//TODO thêm vào trước khách hàng dùng prev
				newCustomer->prev = customerX->prev;
				customerX->prev = newCustomer;
				newCustomer->next = customerX;
				newCustomer->prev->next = newCustomer;
			}
		}
		// Cập nhật trạng thái inDisk cho khách vừa từ hàng chờ vào
		customerTime* temp = CustomerTimeHead;
		while (true)
		{
			if (temp->data = newCustomer)
			{
				temp->inDisk = true;
				break;
			}
			temp = temp->next;
		}	
		temp = nullptr;
		//& lên món cho anh mới vô nào đưa ảnh thành khách hàng X
		customerX = newCustomer;
		//& cập nhật số lượng khách trong bàn bàn
		sizeCustomerInDesk++;
	}
	return;
}

int imp_res::inssort2(customer* A, int n, int incr)
{	
	int swap_time = 0;
	for (int i = incr; i < n; i += incr)
	{
		for (int j = i; (j >= incr) && getCustomerAt(customerQueueHead, j)->energy > getCustomerAt(customerQueueHead, j - incr)->energy; j -= incr)
		{
			//swap(getCustomerAt(customerQueueHead, j), getCustomerAt(customerQueueHead, j - incr)); Work in progress
			customer* swap1 = getCustomerAt(customerQueueHead, j);
			customer* swap2 = getCustomerAt(customerQueueHead, j - incr);
			customer* temp;
			if (swap1 == customerQueueHead)
				customerQueueHead = swap2;
			else if (swap2 == customerQueueHead)
				customerQueueHead = swap1;
			if (swap1 == customerQueueTail)
				customerQueueTail = swap2;
			else if (swap2 == customerQueueTail)
				customerQueueTail = swap1;

			// Swapping swap1 and swap2
			temp = swap1->next;
			swap1->next = swap2->next;
			swap2->next = temp;

			if (swap1->next != nullptr)
				swap1->next->prev = swap1;
			if (swap2->next != nullptr)
				swap2->next->prev = swap2;

			temp = swap1->prev;
			swap1->prev = swap2->prev;
			swap2->prev = temp;

			if (swap1->prev != nullptr)
				swap1->prev->next = swap1;
			if (swap2->prev != nullptr)
				swap2->prev->next = swap2;
					swap_time++;
		}
	}
	return swap_time;
}

void imp_res::PURPLE()
{
	if(sizeCustomerQueue <= 1) return;
	int removeBLUE = 0;

	//* bước 1 tìm vị trí của min abs(energy)
	customerTime* temp = CustomerTimeTail;
	customerTime* max = nullptr;
	for(int i = 0; i < sizeCustomerQueue + sizeCustomerInDesk; i++)
	{
		if(temp->inDisk == 0 && max == nullptr) max = temp;
		else if(temp->inDisk == 0 && abs(temp->data->energy) > abs(max->data->energy)) max = temp;
		temp = temp->prev;
	}

	int n = 1; //! kích thước danh sách cần sort
	// tìm vị trí của khách hàng tương ứng trong hang chờ
	customer* t = customerQueueHead;
	while(t != max->data)
	{
		n++;
		t = t->next;
	}

	//* bước 2 sort
	for(int i = n / 2; i > 2; i /= 2)
	{
		//* phần tử bắt đầu của sort từ 0 -> i 	
		for(int j = 0; j < i; j++)
		{
			// tiến hành sort với index bắt đầu customerQueue[j]
			// mỗi bước nhảy là i -> nghĩa là so sánh Q[j], Q[j+i], ...
			// n - j là kích thước của mảng hiện tại
			removeBLUE += inssort2(getCustomerAt(customerQueueHead, j), n - j, i);
		}
	}
	removeBLUE += inssort2(customerQueueHead, n, 1);
	//* BƯỚC 3 XÓA
	this->BLUE(removeBLUE % MAXSIZE);
}

// Logic REVERSAL : từ customerX theo ngược chiều kim đồng hồ, 
// chọn lấy thằng chưa swap theo cùng chiều kim đồng hồ có cùng 
// là chú thuật sư hay oán linh để swap
void imp_res::REVERSAL()
{
	// Có không được 3 khách đảo sao được?
	if (sizeCustomerInDesk <= 2) return;
	int numOfElementReversal = sizeCustomerInDesk / 2;
	// Reversal từng loại khách một
	customer* customer_root = customerX;
	customer* customer_root_next = customerX;
	customer* customer_magician = customerX->next;
	customer* customer_magician_next = customerX->next;
	customer* customer_spirit = customerX->next;
	customer* customer_spirit_next = customerX->next;
	customer* temp;
	// Loop sẵn đến vị trí cần đổi
	while (customer_magician->energy < 0) 
	{
		customer_magician = customer_magician->next;
		if (customer_magician == customerX) break;
	}
	while (customer_spirit->energy > 0) 
	{
		customer_spirit = customer_spirit->next;
		if (customer_spirit == customerX) break;
	}
	for (int i = 0; i < numOfElementReversal; i++)
	{	
		// Lưu trữ lại vị trí của khách kế tiếp
		customer_root_next = customer_root->next;
		customer_magician_next = customer_magician->next;
		customer_spirit_next = customer_spirit->next;
		while (customer_magician_next->energy < 0) 
		{
			customer_magician_next = customer_magician_next->next;
			if (customer_magician_next == customerX) break;
		}
		while (customer_spirit_next->energy < 0) 
		{
			customer_spirit_next = customer_spirit_next->next;
			if (customer_spirit_next == customerX) break;
		}
		// Swap chỗ ngồi của khách
		// Nếu khách là chứ thuật sư
		if (customer_root->energy > 0)
		{
    		temp = customer_root->next; 
			customer_root->next = customer_magician->next; 
			customer_magician->next = temp; 
    		customer_root->next->prev = customer_root; 
        	customer_magician->next->prev = customer_magician; 

    		temp = customer_root->prev; 
			customer_root->prev = customer_magician->prev; 
			customer_magician->prev = temp; 
        	customer_root->prev->next = customer_root; 
        	customer_magician->prev->next = customer_magician; 
		}
		// Nếu khách là oán linh
		else
		{
			temp = customer_root->next; 
			customer_root->next = customer_spirit->next; 
			customer_spirit->next = temp; 
    		customer_root->next->prev = customer_root; 
        	customer_spirit->next->prev = customer_spirit; 

    		temp = customer_root->prev; 
			customer_root->prev = customer_spirit->prev; 
			customer_spirit->prev = temp; 
        	customer_root->prev->next = customer_root; 
        	customer_spirit->prev->next = customer_spirit; 
		}
		// Tính toán lại customer_root, customer_magican, customer_spirit
		customer_root = customer_root_next;
		customer_magician = customer_magician_next;
		customer_spirit = customer_magician_next;
	}
	// Destructor
	customer_root = nullptr;
	customer_root_next = nullptr;
	customer_magician = nullptr;
	customer_magician_next = nullptr;
	customer_spirit = nullptr;
	customer_spirit_next = nullptr;
	temp = nullptr;
	return;
}

// Đầu tiên dùng brute force tìm
void imp_res::UNLIMITED_VOID()
{	
	if (sizeCustomerInDesk < 4) return;
	customer* result;
	customer* temp1 = customerX;
	customer* temp2 = customerX;
	int glo_min = INT8_MAX;
	int numEleOfMin = 0;
	int temp_min = 0;
	// i tượng trưng cho số phần tử của dãy con đang xét
	// brute-force tìm tất cả các chuỗi rồi so sánh
	for (int i = 4; i <= sizeCustomerInDesk; i++)
	{	
		temp1 = customerX;
		temp2 = customerX;
		temp_min = temp1->energy;
		for (int j = 1; j < i; j++) 
		{
			temp2 = temp2->next;
			temp_min += temp2->energy;
		}
		if (i == sizeCustomerInDesk)
		{
			if (temp_min <= glo_min)
			{	
				glo_min = temp_min;
				result = temp1;
				numEleOfMin = i;
			}
		}
		else
		{
			for (int j = 0; j < sizeCustomerInDesk; j++)
			{
				if (temp_min <= glo_min)
				{	
					glo_min = temp_min;
					result = temp1;
					numEleOfMin = i;
				}
				temp_min -= temp1->energy;
				temp1 = temp1->next;
				temp2 = temp2->next;
				temp_min += temp2->energy;
			}
		}
	}
	temp1 = nullptr;
	temp2 = nullptr;
	// In dãy vừa tìm được từ phần tử có energy nhỏ nhất
	// B1 : Tìm phần tử nhỏ nhất
	customer* temp = result;
	customer* minEle = temp;
	int count = 0;
	glo_min = result->energy;
	temp = temp->next;
	for (int i = 1; i < numEleOfMin; i++)
	{
		if (temp->energy < glo_min)
		{	
			glo_min = temp->energy;
			minEle = temp;
			count = i;
		}
		temp = temp->next;
	}
	// B2 : In phần tử
	temp = minEle;
	for (int i = count; i < numEleOfMin; i++)
	{
		temp->print();
		temp = temp->next;
	}
	temp = result;
	for (int i = 0; i < count; i++)
	{
		temp->print();
		temp = temp->next;
	}
	result = nullptr;
	minEle = nullptr;
	temp = nullptr;
	return;
}

void imp_res::DOMAIN_EXPANSION()
{
	int positive_energy = 0;
	int negative_energy = 0;
	customerTime* temp = CustomerTimeHead;
	// Tính tổng năng lượng 2 giới
	for (int i = 0; i < sizeCustomerInDesk + sizeCustomerQueue; i++)
	{
		if (temp->data->energy > 0) positive_energy += temp->data->energy;
		else negative_energy += temp->data->energy;
		temp = temp->next;
	}
	temp = CustomerTimeTail;
	negative_energy = abs(negative_energy);
	if (positive_energy >= negative_energy)
	{
		while (temp != nullptr)
		{
			if (temp->data->energy < 0)
			{	
				// Cập nhật vị trí trong Time
				if (temp == CustomerTimeHead) CustomerTimeHead = CustomerTimeHead->next;
				if (temp == CustomerTimeTail) CustomerTimeTail = CustomerTimeTail->prev;
				// Đuổi khách trong bàn
				if (temp->inDisk == true)
				{	
					customerTime* customerTimeDelete = temp;
					// In thông tin khách bị đuổi
					temp->data->print();
					// Nối 2 node trước và sau customerTimeDelete lại
					if (customerTimeDelete->prev != nullptr) customerTimeDelete->prev->next = customerTimeDelete->next;
					if (customerTimeDelete->next != nullptr) customerTimeDelete->next->prev = customerTimeDelete->prev;
					// Cập nhật customerX
					if (customerTimeDelete->data->energy > 0) customerX = customerTimeDelete->data->next;
					else customerX = customerTimeDelete->data->prev;
					if (customerTimeDelete->data->prev != nullptr) customerTimeDelete->data->prev->next = customerTimeDelete->data->next;
					if (customerTimeDelete->data->next != nullptr) customerTimeDelete->data->next->prev = customerTimeDelete->data->prev;
					delete customerTimeDelete->data;
					delete customerTimeDelete;
					customerTimeDelete->data = nullptr;
					customerTimeDelete = nullptr;
					sizeCustomerInDesk--;
				}
				// Đuổi khách trong hàng đợi
				else
				{
					customerTime* customerTimeDelete = temp;
					// Nối 2 node trước và sau customerTimeDelete lại
					temp->data->print();
					if (customerTimeDelete->prev != nullptr) customerTimeDelete->prev->next = customerTimeDelete->next;
					if (customerTimeDelete->next != nullptr) customerTimeDelete->next->prev = customerTimeDelete->prev;
					// Cập nhật đầu và cuối hàng đợi
					if (customerTimeDelete->data == customerQueueHead) customerQueueHead = customerQueueHead->next;
					if (customerTimeDelete->data == customerQueueTail) customerQueueTail = customerQueueTail->prev;
					if (customerTimeDelete->data->prev != nullptr) customerTimeDelete->data->prev->next = customerTimeDelete->data->next;
					if (customerTimeDelete->data->next != nullptr) customerTimeDelete->data->next->prev = customerTimeDelete->data->prev;
					delete customerTimeDelete->data;
					delete customerTimeDelete;
					customerTimeDelete->data = nullptr;
					customerTimeDelete = nullptr;
					sizeCustomerQueue--;
				}
			}
			else 
			{
				// DO NOTHING
			}
			temp = temp->prev;
		}
	}
	else
	{
		while (temp != nullptr)
		{
			if (temp->data->energy > 0)
			{
				// Cập nhật vị trí trong Time
				if (temp == CustomerTimeHead) CustomerTimeHead = CustomerTimeHead->next;
				if (temp == CustomerTimeTail) CustomerTimeTail = CustomerTimeTail->prev;
				// Đuổi khách trong bàn
				if (temp->inDisk == true)
				{	
					customerTime* customerTimeDelete = temp;
					temp->data->print();
					// Nối 2 node trước và sau customerTimeDelete lại
					if (customerTimeDelete->prev != nullptr) customerTimeDelete->prev->next = customerTimeDelete->next;
					if (customerTimeDelete->next != nullptr) customerTimeDelete->next->prev = customerTimeDelete->prev;
					// Cập nhật customerX
					if (customerTimeDelete->data->energy > 0) customerX = customerTimeDelete->data->next;
					else customerX = customerTimeDelete->data->prev;
					if (customerTimeDelete->data->prev != nullptr) customerTimeDelete->data->prev->next = customerTimeDelete->data->next;
					if (customerTimeDelete->data->next != nullptr) customerTimeDelete->data->next->prev = customerTimeDelete->data->prev;
					delete customerTimeDelete->data;
					delete customerTimeDelete;
					customerTimeDelete->data = nullptr;
					customerTimeDelete = nullptr;
					sizeCustomerInDesk--;
				}
				// Đuổi khách trong hàng đợi
				else
				{
					customerTime* customerTimeDelete = temp;
					temp->data->print();
					// Nối 2 node trước và sau customerTimeDelete lại
					if (customerTimeDelete->prev != nullptr) customerTimeDelete->prev->next = customerTimeDelete->next;
					if (customerTimeDelete->next != nullptr) customerTimeDelete->next->prev = customerTimeDelete->prev;
					// Cập nhật đầu và cuối hàng đợi
					if (customerTimeDelete->data == customerQueueHead) customerQueueHead = customerQueueHead->next;
					if (customerTimeDelete->data == customerQueueTail) customerQueueTail = customerQueueTail->prev;
					if (customerTimeDelete->data->prev != nullptr) customerTimeDelete->data->prev->next = customerTimeDelete->data->next;
					if (customerTimeDelete->data->next != nullptr) customerTimeDelete->data->next->prev = customerTimeDelete->data->prev;
					delete customerTimeDelete->data;
					delete customerTimeDelete;
					customerTimeDelete->data = nullptr;
					customerTimeDelete = nullptr;
					sizeCustomerQueue--;
				}
			}
			else 
			{
				// DO NOTHING
			}
			temp = temp->prev;
		}
	}
	return;
}

void imp_res::LIGHT(int num)
{	
	if (num > 0) 		// In thông tin của tất cả các vị khách 
						// trong bàn ăn theo chiều kim đồng hồ
	{
		customer* temp = customerX;
		for (int i = 0; i < sizeCustomerInDesk; i++)
		{
			temp->print();
			temp = temp->next;
		}
		temp = nullptr;
	}
	else if (num < 0) 	// In thông tin của tất cả các vị khách
	                	// trong bàn ăn theo ngược chiều kim đồng hồ
	{
		customer* temp = customerX;
		for (int i = 0; i < sizeCustomerInDesk; i++)
		{	
			temp->print();
			temp = temp->prev;
		}
		temp = nullptr;
	}
	else 				// In thông tin của tất cả các vị khách 
						// trong hàng đợi từ đầu đến cuối
	{	
		if (sizeCustomerQueue == 0) return;
		customer* temp = customerQueueHead;
		for (int i = 0; i < sizeCustomerQueue; i++)
		{
			temp->print();
			temp = temp->next;
		}
		temp = nullptr;
	}
	return;
}