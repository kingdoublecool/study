class HeatingPlan() {
  withinRange(aNumberRange) {
    return (aNumberRange.low >= this._temperatureRange.low) && (aNumberRange.high <= this._temperatureRange.high);
  }
}

aPlan = new HeatingPlan();
if (!aPlan.withinRange(aRoom.daysTempRange)) 
  alerts.push("room temperature went outside range");

