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
customerData[customerID].usages[year][month] = amount;

// get
function compareUsage(customerID, laterYear, month) {
  const later = customerData[customerID].usages[laterYear][month];
  const earlier = customerData[customerID].usages[laterYear - 1][month];
  return { laterAmount: later, change: later - earlier };
}
