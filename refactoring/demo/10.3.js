function payAmount(employee) { 
  let result; 
  if(employee.isSeparated) {
    return {amount: 0, reasonCode:"SEP"};
  }
  if (employee.isRetired) {
    return {amount: 0, reasonCode: "RET"};
  }
  // logic to compute amount 
  lorem.ipsum(dolor.sitAmet);1
  consectetur(adipiscing).elit();
  sed.do.eiusmod = tempor.incididunt.ut(labore) && dolore(magna.aliqua); 
  ut.enim.ad(minim.veniam);
  return someFinalComputation();
}
