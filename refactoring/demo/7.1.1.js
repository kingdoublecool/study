"1920": {
name: "martin",
id: "1920",
usages: {
"2016": {
 "1": 50,
 "2": 55,
 // remaining months of the year
},
"2015": {
 "1": 70,
 "2": 63,
 // remaining months of the year
}
}
},
"38673": {
name: "neal",
id: "38673",
// more customers in a similar form


// set
getCustomerData().setUsage(customerID, year, month, amount);

// get
function compareUsage(customerID, laterYear, month) {
  const later = getCustomerData().rawData[customerID].usages[laterYear][month];
  const earlier = getCustomerData().rawData[customerID].usages[laterYear - 1][month];
  return { laterAmount: later, change: later - earlier };
}

function getCustomerData() {
  return customerData;
}

class CustomerData {
  constructor(data) {
    this._data = data;
  }
  setUsage(customerID, year, month, amount) {
    this._data[customerID].usages[year][month] = amount;
  }
  get rawData() {
    return _.cloneDeep(this._data);
  }
}
