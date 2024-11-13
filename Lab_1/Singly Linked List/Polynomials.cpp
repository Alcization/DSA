void Polynomial::insertTerm(const Term& term) {
    // STUDENT ANSWER
    if (term.coeff != 0){
        if (terms->size() == 0 || terms->get(terms->size() - 1).exp > term.exp) terms->add(term);
        else
        {
            int i = 0;
            SLinkedList<Term>::Iterator it;
            for (it = this->terms->begin(); it != this->terms->end(); ++it)
            {
                if (term.exp == (*it).exp)
                {
                    if (term.coeff + (*it).coeff == 0) it.remove();
                    else it.set(Term(term.coeff + (*it).coeff, term.exp));
                    break;
                }
                if (term.exp > (*it).exp)
                {
                    terms->add(i, term);
                    break;
                }
                i++;
            }
        }
    }
    SLinkedList<Term>::Iterator it;
    for (it = this->terms->begin(); it != this->terms->end(); ++it)
    {
        if ((*it).coeff == 0) it.remove();
    }
}

void Polynomial::insertTerm(double coeff, int exp) {
    // STUDENT ANSWER
    const Term* newT = new Term(coeff, exp);
    insertTerm(*newT);
}











































//
//
//
void Polynomial::insertTerm(const Term& term) {
    SLinkedList<Term>::Iterator it;
    for (it = this->terms->begin(); it != this->terms->end(); it++) {
        const Term& currentTerm = *it; 
        if (currentTerm.exp == term.exp) {
            const_cast<Term&>(currentTerm).coeff += term.coeff; 
            return;
        } else if (currentTerm.exp < term.exp) {
            break;
        }
    }
    
    // ???? no function call set()
    this->terms->set(it, term);
}

























void Polynomial::insertTerm(double coeff, int exp) {
    insertTerm(Term(coeff, exp));
}
