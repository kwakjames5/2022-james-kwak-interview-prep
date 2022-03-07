class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // sort the deck in reverse order by using rbegin and rend (reverse begin and reverse end)
        sort(deck.rbegin(), deck.rend());
        
        // use deque bc we need front and back for this one
        deque<int> new_deck;
        // start the new deck by pushing the first element (aka the largest) of the deck
        new_deck.push_back(deck[0]);
        
        for(int i = 1; i < deck.size(); i++)
        {
            // store the last element in the deck so far
            int temp = new_deck.back();
            
            // this is the pattern that happens every iteration of revealing the deck cards
            // the last element is removed, then it is pushed to the front, followed by the next card in the deck
            // which should be the next largest number
            // continue for all numbers
            new_deck.pop_back();
            new_deck.push_front(temp);
            new_deck.push_front(deck[i]);
        }
        
        vector<int> return_deck;
        deque<int>::iterator deque_it;
        for(deque_it = new_deck.begin(); deque_it != new_deck.end(); deque_it++)
        {
            return_deck.push_back(*deque_it);
        }
        return return_deck;
    }
};