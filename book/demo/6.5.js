const newEnglanders = someCustomers.filter(c => inNewEngland(c));

function inNewEngland(aCustomer) {
  return ["MA", "CT", "ME", "VT", "NH", "RI"].includes(aCustomer.address.state);
}



