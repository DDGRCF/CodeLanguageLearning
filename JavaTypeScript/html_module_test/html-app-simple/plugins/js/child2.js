"use strict";
const child2 = `
<div>
  <button @click="count++" style="width: 50px; height: 25px; background-color: pink;"></button>
  <p>child2: {{ count }}</p>
</div>
`

export default {
  data() {
    return { count:  0}
  },
  template: child2,
}