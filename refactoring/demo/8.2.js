class Customer {
  constructor(name, discountRate) {
    this._name = name;
    this._setDiscountRate(discountRate);
    this._contract = new CustomerContract(dateToday());
  }
  get discountRate() {return this._contract.discountRate;}
  _setDiscountRate(aNumber) {this._contract.discountRate = aNumber;}
  becomePreferred() {
    this._setDiscountRate(this.discountRate + 0.03);
    // other nice things
  }
  applyDiscount(amount) {
    return amount.subtract(amount.multiply(this.discountRate));
  }
}
class CustomerContract {
  constructor(startDate, discountRate) {
    this._startDate = startDate;
    this._discountRate = discountRate;
  }
  get discountRate()  {return this._discountRate;}
  set discountRate(arg) {this._discountRate = arg;}
}
