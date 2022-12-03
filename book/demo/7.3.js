class Order() {
  constructor(data) {
    this.priority = data.priority;
    // more initialization
  }
}

highPriorityCount = orders
  .filter(o => "high" === o.priority ||
                "rush" === o.priority)
  .length
;

