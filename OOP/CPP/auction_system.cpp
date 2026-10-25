#include <iostream>

class Item {
public:
    char itemName[50];
    double startingPrice;
    double currentBid;
    int highestBidderId;

    Item(const char* name, double price) {
        for (int i = 0; i < 49 && name[i] != '\0'; i++) {
            itemName[i] = name[i];
            itemName[i + 1] = '\0';
        }
        startingPrice = price;
        currentBid = price;
        highestBidderId = -1;
    }
};

class Bidder {
public:
    char bidderName[50];

    Bidder(const char* name) {
        for (int i = 0; i < 49 && name[i] != '\0'; i++) {
            bidderName[i] = name[i];
            bidderName[i + 1] = '\0';
        }
    }

    void placeBid(class Auction& auction, Item* item, double bidAmount);
};

class Auction {
private:
    struct Bid {
        Bidder* bidder;
        Item* item;
        double amount;
    };

    Item* items[100];  // Assume a maximum of 100 items
    int itemCount;

    Bid bids[100];     // Assume a maximum of 100 bids
    int bidCount;

public:
    Auction() : itemCount(0), bidCount(0) {}

    void listItem(Item* item) {
        if (itemCount < 100) {
            items[itemCount++] = item;
        } else {
            std::cout << "Item list is full!\n";
        }
    }

    void addBid(Bidder* bidder, Item* item, double amount) {
        if (bidCount < 100) {
            bids[bidCount++] = {bidder, item, amount};
            std::cout << bidder->bidderName << " placed a bid of $" << amount << " on " << item->itemName << "\n";
        } else {
            std::cout << "Bid list is full!\n";
        }
    }

    void closeAuction() {
        std::cout << "Auction results:\n";
        for (int i = 0; i < itemCount; ++i) {
            Item* item = items[i];
            Bid* highestBid = nullptr;

            for (int j = 0; j < bidCount; ++j) {
                if (bids[j].item == item && (!highestBid || bids[j].amount > highestBid->amount)) {
                    highestBid = &bids[j];
                }
            }

            if (highestBid) {
                std::cout << item->itemName << " sold to " << highestBid->bidder->bidderName 
                          << " for $" << highestBid->amount << "\n";
            } else {
                std::cout << item->itemName << " did not receive any bids.\n";
            }
        }
    }
};

void Bidder::placeBid(Auction& auction, Item* item, double bidAmount) {
    auction.addBid(this, item, bidAmount);
}

int main() {
    Item item1("Laptop", 500);
    Item item2("Smartphone", 300);

    Bidder bidder1("sidak");
    Bidder bidder2("jot");

    Auction auction;
    auction.listItem(&item1);
    auction.listItem(&item2);

    bidder1.placeBid(auction, &item1, 550);
    bidder2.placeBid(auction, &item1, 600);
    bidder1.placeBid(auction, &item2, 350);

    auction.closeAuction();

    return 0;
}
