class Site {
  get customer() {
    return (this._customer === "unknown") ? new UnknownCustomer() : this._customer;
  }
}
class Customer {
  get name()           {...}
  get billingPlan()    {...} 
  set billingPlan(arg) {...} 
  get paymentHistory() {...}
}
class UnknownCustomer {
  get name() {return "occupant";}
  get billingPlan() {return registry.billingPlans.basic;}
  get paymentHistory() {return new NullPaymentHistory();}
}
class NullPaymentHistory {
  get weeksDelinquentInLastYear() {return 0;}
}
class client1 {
  const aCustomer = site.customer;
  // ... lots of intervening code ... 
  const customerName = aCustomer.name;
}
class client2 {
  const plan = aCustomer.billingPlan;
}
class client3 {
  aCustomer.billingPlan = newPlan;
}
class client4 {
  const weeksDelinquent = aCustomer.paymentHistory.weeksDelinquentInLastYear;
}
