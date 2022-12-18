class Site {
  get customer() {return this._customer;}
}
class Customer {
  get name()           {...}
  get billingPlan()    {...} 
  set billingPlan(arg) {...} 
  get paymentHistory() {...}
}
class client1 {
  const aCustomer = site.customer;
  // ... lots of intervening code ... 
  let customerName;
  if (aCustomer === "unknown")
  customerName = "occupant"; 
  else customerName = aCustomer.name;
}
class client2 {
  const plan = (aCustomer === "unknown") ? 
    registry.billingPlans.basic
    : aCustomer.billingPlan;
}
class client3 {
  if (aCustomer !== "unknown") aCustomer.billingPlan = newPlan;
}
class client4 {
  const weeksDelinquent = (aCustomer === "unknown") ?
    0
    : aCustomer.paymentHistory.weeksDelinquentInLastYear;
}
